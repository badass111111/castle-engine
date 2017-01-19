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
    function GetBboxCenter: TVector3Single;
    procedure SetBboxCenter(const Value: TVector3Single);
    function GetBboxSize: TVector3Single;
    procedure SetBboxSize(const Value: TVector3Single);
  public
    property BboxCenter: TVector3Single read GetBboxCenter write SetBboxCenter;
    property BboxSize: TVector3Single read GetBboxSize write SetBboxSize;

{$endif read_interface}

{$ifdef read_implementation}

{ TStaticGroupNode ----------------------------------------------- }

function TStaticGroupNode.GetBboxCenter: TVector3Single;
begin
  Result := FdBboxCenter.Value;
end;

procedure TStaticGroupNode.SetBboxCenter(const Value: TVector3Single);
begin
  FdBboxCenter.Send(Value);
end;

function TStaticGroupNode.GetBboxSize: TVector3Single;
begin
  Result := FdBboxSize.Value;
end;

procedure TStaticGroupNode.SetBboxSize(const Value: TVector3Single);
begin
  FdBboxSize.Send(Value);
end;

{$endif read_implementation}