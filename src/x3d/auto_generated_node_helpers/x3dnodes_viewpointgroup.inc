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
    function GetCenter: TVector3Single;
    procedure SetCenter(const Value: TVector3Single);
    function GetDescription: string;
    procedure SetDescription(const Value: string);
    function GetDisplayed: boolean;
    procedure SetDisplayed(const Value: boolean);
    function GetRetainUserOffsets: boolean;
    procedure SetRetainUserOffsets(const Value: boolean);
    function GetSize: TVector3Single;
    procedure SetSize(const Value: TVector3Single);
  public
    property Center: TVector3Single read GetCenter write SetCenter;
    property Description: string read GetDescription write SetDescription;
    property Displayed: boolean read GetDisplayed write SetDisplayed;
    property RetainUserOffsets: boolean read GetRetainUserOffsets write SetRetainUserOffsets;
    property Size: TVector3Single read GetSize write SetSize;

{$endif read_interface}

{$ifdef read_implementation}

{ TViewpointGroupNode ----------------------------------------------- }

function TViewpointGroupNode.GetCenter: TVector3Single;
begin
  Result := FdCenter.Value;
end;

procedure TViewpointGroupNode.SetCenter(const Value: TVector3Single);
begin
  FdCenter.Send(Value);
end;

function TViewpointGroupNode.GetDescription: string;
begin
  Result := FdDescription.Value;
end;

procedure TViewpointGroupNode.SetDescription(const Value: string);
begin
  FdDescription.Send(Value);
end;

function TViewpointGroupNode.GetDisplayed: boolean;
begin
  Result := FdDisplayed.Value;
end;

procedure TViewpointGroupNode.SetDisplayed(const Value: boolean);
begin
  FdDisplayed.Send(Value);
end;

function TViewpointGroupNode.GetRetainUserOffsets: boolean;
begin
  Result := FdRetainUserOffsets.Value;
end;

procedure TViewpointGroupNode.SetRetainUserOffsets(const Value: boolean);
begin
  FdRetainUserOffsets.Send(Value);
end;

function TViewpointGroupNode.GetSize: TVector3Single;
begin
  Result := FdSize.Value;
end;

procedure TViewpointGroupNode.SetSize(const Value: TVector3Single);
begin
  FdSize.Send(Value);
end;

{$endif read_implementation}