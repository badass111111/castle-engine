{ -*- buffer-read-only: t -*-

  Copyright 2015-2017 Michalis Kamburelis.

  This file is part of "Castle Game Engine".

  "Castle Game Engine" is free software; see the file COPYING.txt,
  included in this distribution, for details about the copyright.

  "Castle Game Engine" is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

  ----------------------------------------------------------------------------
}

{ Automatically generated X3D node class helpers.
  Do not edit manually, instead regenerate using
  castle_game_engine/src/x3d/doc/generate_x3d_nodes_to_pascal.lpr . }

{$ifdef read_interface}

  private
    function GetLoop: boolean;
    procedure SetLoop(const Value: boolean);
    function GetPauseTime: TFloatTime;
    procedure SetPauseTime(const Value: TFloatTime);
    function GetResumeTime: TFloatTime;
    procedure SetResumeTime(const Value: TFloatTime);
    function GetStartTime: TFloatTime;
    procedure SetStartTime(const Value: TFloatTime);
    function GetStopTime: TFloatTime;
    procedure SetStopTime(const Value: TFloatTime);
  public
    property Loop: boolean read GetLoop write SetLoop;
    property PauseTime: TFloatTime read GetPauseTime write SetPauseTime;
    property ResumeTime: TFloatTime read GetResumeTime write SetResumeTime;
    property StartTime: TFloatTime read GetStartTime write SetStartTime;
    property StopTime: TFloatTime read GetStopTime write SetStopTime;

{$endif read_interface}

{$ifdef read_implementation}

{ TAbstractTimeDependentNode ----------------------------------------------- }

function TAbstractTimeDependentNode.GetLoop: boolean;
begin
  Result := FdLoop.Value;
end;

procedure TAbstractTimeDependentNode.SetLoop(const Value: boolean);
begin
  FdLoop.Send(Value);
end;

function TAbstractTimeDependentNode.GetPauseTime: TFloatTime;
begin
  Result := FdPauseTime.Value;
end;

procedure TAbstractTimeDependentNode.SetPauseTime(const Value: TFloatTime);
begin
  FdPauseTime.Send(Value);
end;

function TAbstractTimeDependentNode.GetResumeTime: TFloatTime;
begin
  Result := FdResumeTime.Value;
end;

procedure TAbstractTimeDependentNode.SetResumeTime(const Value: TFloatTime);
begin
  FdResumeTime.Send(Value);
end;

function TAbstractTimeDependentNode.GetStartTime: TFloatTime;
begin
  Result := FdStartTime.Value;
end;

procedure TAbstractTimeDependentNode.SetStartTime(const Value: TFloatTime);
begin
  FdStartTime.Send(Value);
end;

function TAbstractTimeDependentNode.GetStopTime: TFloatTime;
begin
  Result := FdStopTime.Value;
end;

procedure TAbstractTimeDependentNode.SetStopTime(const Value: TFloatTime);
begin
  FdStopTime.Send(Value);
end;

{$endif read_implementation}