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
    function GetAmbientIntensity: Single;
    procedure SetAmbientIntensity(const Value: Single);
    function GetDiffuseColor: TCastleColorRGB;
    procedure SetDiffuseColor(const Value: TCastleColorRGB);
    function GetEmissiveColor: TCastleColorRGB;
    procedure SetEmissiveColor(const Value: TCastleColorRGB);
    function GetShininess: Single;
    procedure SetShininess(const Value: Single);
    function GetSpecularColor: TCastleColorRGB;
    procedure SetSpecularColor(const Value: TCastleColorRGB);
    function GetTransparency: Single;
    procedure SetTransparency(const Value: Single);
    function GetMirror: Single;
    procedure SetMirror(const Value: Single);
    function GetReflSpecularExp: Single;
    procedure SetReflSpecularExp(const Value: Single);
    function GetTransSpecularExp: Single;
    procedure SetTransSpecularExp(const Value: Single);
  public
    property AmbientIntensity: Single read GetAmbientIntensity write SetAmbientIntensity;
    property DiffuseColor: TCastleColorRGB read GetDiffuseColor write SetDiffuseColor;
    property EmissiveColor: TCastleColorRGB read GetEmissiveColor write SetEmissiveColor;
    property Shininess: Single read GetShininess write SetShininess;
    property SpecularColor: TCastleColorRGB read GetSpecularColor write SetSpecularColor;
    property Transparency: Single read GetTransparency write SetTransparency;
    property Mirror: Single read GetMirror write SetMirror;
    property ReflSpecularExp: Single read GetReflSpecularExp write SetReflSpecularExp;
    property TransSpecularExp: Single read GetTransSpecularExp write SetTransSpecularExp;

{$endif read_interface}

{$ifdef read_implementation}

{ TMaterialNode ----------------------------------------------- }

function TMaterialNode.GetAmbientIntensity: Single;
begin
  Result := FdAmbientIntensity.Value;
end;

procedure TMaterialNode.SetAmbientIntensity(const Value: Single);
begin
  FdAmbientIntensity.Send(Value);
end;

function TMaterialNode.GetDiffuseColor: TCastleColorRGB;
begin
  Result := FdDiffuseColor.Value;
end;

procedure TMaterialNode.SetDiffuseColor(const Value: TCastleColorRGB);
begin
  FdDiffuseColor.Send(Value);
end;

function TMaterialNode.GetEmissiveColor: TCastleColorRGB;
begin
  Result := FdEmissiveColor.Value;
end;

procedure TMaterialNode.SetEmissiveColor(const Value: TCastleColorRGB);
begin
  FdEmissiveColor.Send(Value);
end;

function TMaterialNode.GetShininess: Single;
begin
  Result := FdShininess.Value;
end;

procedure TMaterialNode.SetShininess(const Value: Single);
begin
  FdShininess.Send(Value);
end;

function TMaterialNode.GetSpecularColor: TCastleColorRGB;
begin
  Result := FdSpecularColor.Value;
end;

procedure TMaterialNode.SetSpecularColor(const Value: TCastleColorRGB);
begin
  FdSpecularColor.Send(Value);
end;

function TMaterialNode.GetTransparency: Single;
begin
  Result := FdTransparency.Value;
end;

procedure TMaterialNode.SetTransparency(const Value: Single);
begin
  FdTransparency.Send(Value);
end;

function TMaterialNode.GetMirror: Single;
begin
  Result := FdMirror.Value;
end;

procedure TMaterialNode.SetMirror(const Value: Single);
begin
  FdMirror.Send(Value);
end;

function TMaterialNode.GetReflSpecularExp: Single;
begin
  Result := FdReflSpecularExp.Value;
end;

procedure TMaterialNode.SetReflSpecularExp(const Value: Single);
begin
  FdReflSpecularExp.Send(Value);
end;

function TMaterialNode.GetTransSpecularExp: Single;
begin
  Result := FdTransSpecularExp.Value;
end;

procedure TMaterialNode.SetTransSpecularExp(const Value: Single);
begin
  FdTransSpecularExp.Send(Value);
end;

{$endif read_implementation}