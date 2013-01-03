{
  Copyright 2012-2013 Michalis Kamburelis.

  This file is part of "Castle Game Engine".

  "Castle Game Engine" is free software; see the file COPYING.txt,
  included in this distribution, for details about the copyright.

  "Castle Game Engine" is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

  ----------------------------------------------------------------------------
}

{ Example of a fully-working 3D FPS game. }
program fps_game;

uses SysUtils, Classes, CastleWindow, CastleWarnings, CastleConfig, CastleLevels,
  CastlePlayer, CastleSoundEngine, CastleProgress, CastleWindowProgress,
  CastleResources, CastleControls, CastleKeysMouse, CastleStringUtils,
  GLRenderer, Base3D, CastleFilesUtils, CastleGameNotifications;

var
  Window: TCastleWindow;
  SceneManager: TGameSceneManager; //< same thing as Window.SceneManager
  Player: TPlayer; //< same thing as Window.SceneManager.Player

type
  { Container for buttons and their callbacks.
    You could as well derive descendant of TCastleWindow to keep your
    callbacks, or place these callbacks as methods of Lazarus form. }
  TButtons = class(TComponent)
    ToggleMouseLookButton: TCastleButton;
    ExitButton: TCastleButton;
    RenderDebug3DButton: TCastleButton;
    RenderDebugCaptionsButton: TCastleButton;
    ScrenshotButton: TCastleButton;
    constructor Create(AOwner: TComponent); override;
    procedure ToggleMouseLookButtonClick(Sender: TObject);
    procedure ExitButtonClick(Sender: TObject);
    procedure RenderDebug3DButtonClick(Sender: TObject);
    procedure RenderDebugCaptionsButtonClick(Sender: TObject);
    procedure ScreenshotButtonClick(Sender: TObject);
  end;

constructor TButtons.Create(AOwner: TComponent);
const
  ButtonsMargin = 8;
var
  NextButtonBottom: Integer;
begin
  inherited;

  NextButtonBottom := ButtonsMargin;

  ToggleMouseLookButton := TCastleButton.Create(Application);
  ToggleMouseLookButton.Caption := 'Mouse Look (F4)';
  ToggleMouseLookButton.Toggle := true;
  ToggleMouseLookButton.OnClick := @ToggleMouseLookButtonClick;
  ToggleMouseLookButton.Left := ButtonsMargin;
  ToggleMouseLookButton.Bottom := NextButtonBottom;
  Window.Controls.Add(ToggleMouseLookButton);
  NextButtonBottom += ToggleMouseLookButton.Height + ButtonsMargin;

  ExitButton := TCastleButton.Create(Application);
  ExitButton.Caption := 'Exit (Escape)';
  ExitButton.OnClick := @ExitButtonClick;
  ExitButton.Left := ButtonsMargin;
  ExitButton.Bottom := NextButtonBottom;
  Window.Controls.Add(ExitButton);
  NextButtonBottom += ExitButton.Height + ButtonsMargin;

  RenderDebug3DButton := TCastleButton.Create(Application);
  RenderDebug3DButton.Caption := 'Render debug 3D objects';
  RenderDebug3DButton.Toggle := true;
  RenderDebug3DButton.OnClick := @RenderDebug3DButtonClick;
  RenderDebug3DButton.Left := ButtonsMargin;
  RenderDebug3DButton.Bottom := NextButtonBottom;
  Window.Controls.Add(RenderDebug3DButton);
  NextButtonBottom += RenderDebug3DButton.Height + ButtonsMargin;

  RenderDebugCaptionsButton := TCastleButton.Create(Application);
  RenderDebugCaptionsButton.Caption := 'Render debug captions';
  RenderDebugCaptionsButton.Toggle := true;
  RenderDebugCaptionsButton.OnClick := @RenderDebugCaptionsButtonClick;
  RenderDebugCaptionsButton.Left := ButtonsMargin;
  RenderDebugCaptionsButton.Bottom := NextButtonBottom;
  Window.Controls.Add(RenderDebugCaptionsButton);
  NextButtonBottom += RenderDebugCaptionsButton.Height + ButtonsMargin;

  ScrenshotButton := TCastleButton.Create(Application);
  ScrenshotButton.Caption := 'Screenshot (F5)';
  ScrenshotButton.OnClick := @ScreenshotButtonClick;
  ScrenshotButton.Left := ButtonsMargin;
  ScrenshotButton.Bottom := NextButtonBottom;
  Window.Controls.Add(ScrenshotButton);
  NextButtonBottom += ScrenshotButton.Height + ButtonsMargin;
end;

procedure TButtons.ToggleMouseLookButtonClick(Sender: TObject);
begin
  ToggleMouseLookButton.Pressed := not ToggleMouseLookButton.Pressed;
  Player.Camera.MouseLook := ToggleMouseLookButton.Pressed;
end;

procedure TButtons.ExitButtonClick(Sender: TObject);
begin
  Application.Quit;
end;

procedure TButtons.RenderDebug3DButtonClick(Sender: TObject);
begin
  RenderDebug3DButton.Pressed := not RenderDebug3DButton.Pressed;
  RenderDebug3D := RenderDebug3DButton.Pressed;
end;

procedure TButtons.RenderDebugCaptionsButtonClick(Sender: TObject);
begin
  RenderDebugCaptionsButton.Pressed := not RenderDebugCaptionsButton.Pressed;
  RenderDebugCaptions := RenderDebugCaptionsButton.Pressed;
end;

procedure TButtons.ScreenshotButtonClick(Sender: TObject);
var
  FileName: string;
begin
  { Capture a screenshot straight to a file.
    There are more interesting things that you can do with a screenshot
    (overloaded Window.SaveScreen returns you a TRGBImage and we have
    a whole image library in CastleImages unit to process such image).
    You could also ask for a filename (e.g. by Window.FileDialog).
    But this is just a simple example, and this way we also have
    an opportunity to show how to use Notifications. }
  FileName := FileNameAutoInc(ApplicationName + '_screen_%d.png');
  Window.SaveScreen(FileName);
  Notifications.Show('Saved screen to ' + FileName);
end;

var
  Buttons: TButtons;

procedure Press(Window: TCastleWindowBase; const Event: TInputPressRelease);
begin
  { We simulate button presses on some key presses. There is no automatic
    mechanism to assign key shortcut to a TCastleButton right now.
    Note that we pass Sender = nil to the callbacks, because we know that
    our TButtons callbacks ignore Sender parameter. }
  if Event.IsKey(K_F4) then
    Buttons.ToggleMouseLookButtonClick(nil) else
  if Event.IsKey(CharEscape) then
    Buttons.ExitButtonClick(nil) else
  if Event.IsKey(K_F5) then
    Buttons.ScreenshotButtonClick(nil);
end;

function MyGetApplicationName: string;
begin
  Result := 'fps_game';
end;

begin
  { We use standard FPC ApplicationName function for some names (e.g. Config
    file name), so make sure it's Ok. }
  OnGetApplicationName := @MyGetApplicationName;

  { Write warnings on standard output (console).
    By default, warnings are only written to log, and log by default goes nowhere. }
  OnWarning := @OnWarningWrite;

  Window := TCastleWindow.Create(Application);
  SceneManager := Window.SceneManager;

  { Parse command-line parameters.
    Options parsed by Window.ParseParameters are documented on
    http://castle-engine.sourceforge.net/opengl_options.php .
    Options parsed by SoundEngine.ParseParameters are documented on
    http://castle-engine.sourceforge.net/openal.php#section_options .
    Of course you can also handle your own options, see CastleParameters
    unit: use Parameters.Parse method (or just directly browse Parameters
    string list). }
  Window.FullScreen := true; { by default we open in fullscreen }
  Window.ParseParameters(StandardParseOptions);
  SoundEngine.ParseParameters;

  { Load configuration file. This loads configuration for various parts of the
    engine that add their callbacks to Config.OnLoad, Config.OnSave.
    Of course you can also use this for your game specific purposes,
    as Config is just standard FPC TXMLConfig class (with some extensions,
    see CastleXMLConfig unit). }
  Config.Load;

  { Open window (with OpenGL context). }
  Window.Open;

  { Show progress bars on our Window. }
  Progress.UserInterface := WindowProgressInterface;
  WindowProgressInterface.Window := Window;

  { Load all resources (creatures and items kinds) information from
    resource.xml files found inside ProgramDataPath.
    Similarly, load all available levels information from level.xml
    files inside ProgramDataPath. }
  Resources.LoadFromFiles;
  Levels.LoadFromFiles;

  { Create player. It's not strictly necessary to use Player, but it makes
    some stuff working better/simpler: Player automatically configures
    camera (to use game-like AWSD shortcuts from CastleInputs,
    to use gravity), it adds footsteps etc.
    It's best to assign SceneManager.Player before SceneManager.LoadLevel,
    then Player.Camera is automatically configured as SceneManager.Camera
    and it follows level's properties like PreferredHeight (from level's
    NavigationInfo.avatarSize). }
  Player := TPlayer.Create(SceneManager);
  SceneManager.Items.Add(Player);
  SceneManager.Player := Player;

  { Load initial level.
    This loads and adds 3D model of your level to the 3D world
    (that is to SceneManager.Items). It may also load initial creatures/items
    on levels, waypoints/sectors and other information from so-called
    "placeholders" on the level, see TGameSceneManager.LoadLevel documentation. }
  SceneManager.LoadLevel('example_level');

  { Maybe adjust some rendering properties?
    (SceneManager.MainScene was initialized by SceneManager.LoadLevel) }
  // SceneManager.MainScene.Attributes.Shaders := srAlways; // per-pixel lighting, everything done by shaders

  { Add some buttons.
    We use TCastleButton from CastleControls unit for buttons,
    which are drawn using OpenGL.
    If you use Lazarus and TCastleControl (instead of TCastleWindow)
    you can also consider using Lazarus standard buttons and other components
    on your form.
    The advantage of our TCastleButton is that you can fully configure it,
    regardless of your OS/window manager theme, and in the future it should
    be trivial to style the TCastleButton to match the theme of your game
    (like medieval fantasy of futuristic sci-fi). }
  Buttons := TButtons.Create(Application);

  { Add the Notifications to our window.
    We add a global Notifications object from CastleGameNotifications.
    Of course this is completely optional, you could instead create your own
    TCastleNotifications instance (to not see the default notifications
    made by some engine units) or just don't use notifications at all. }
  Window.Controls.Add(Notifications);

  Window.OnPress := @Press;

  { Run the game loop.
    In more advanced cases, you can also execute each step of the loop
    manually by Application.ProcessMessage, like
    "while Application.ProcessMessage(true, true)
      and <whatever you want> do <whatever you want>;" }
  Application.Run;

  { Save the configuration file. This is commented out for now,
    as this example program does not give user any UI to actually change
    any configuration. }
  //Config.Save;
end.