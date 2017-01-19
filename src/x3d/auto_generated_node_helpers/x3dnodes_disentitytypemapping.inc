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
    function GetCategory: Integer;
    procedure SetCategory(const Value: Integer);
    function GetCountry: Integer;
    procedure SetCountry(const Value: Integer);
    function GetDomain: Integer;
    procedure SetDomain(const Value: Integer);
    function GetExtra: Integer;
    procedure SetExtra(const Value: Integer);
    function GetKind: Integer;
    procedure SetKind(const Value: Integer);
    function GetSpecific: Integer;
    procedure SetSpecific(const Value: Integer);
    function GetSubcategory: Integer;
    procedure SetSubcategory(const Value: Integer);
  public
    property Category: Integer read GetCategory write SetCategory;
    property Country: Integer read GetCountry write SetCountry;
    property Domain: Integer read GetDomain write SetDomain;
    property Extra: Integer read GetExtra write SetExtra;
    property Kind: Integer read GetKind write SetKind;
    property Specific: Integer read GetSpecific write SetSpecific;
    property Subcategory: Integer read GetSubcategory write SetSubcategory;

{$endif read_interface}

{$ifdef read_implementation}

{ TDISEntityTypeMappingNode ----------------------------------------------- }

function TDISEntityTypeMappingNode.GetCategory: Integer;
begin
  Result := FdCategory.Value;
end;

procedure TDISEntityTypeMappingNode.SetCategory(const Value: Integer);
begin
  FdCategory.Send(Value);
end;

function TDISEntityTypeMappingNode.GetCountry: Integer;
begin
  Result := FdCountry.Value;
end;

procedure TDISEntityTypeMappingNode.SetCountry(const Value: Integer);
begin
  FdCountry.Send(Value);
end;

function TDISEntityTypeMappingNode.GetDomain: Integer;
begin
  Result := FdDomain.Value;
end;

procedure TDISEntityTypeMappingNode.SetDomain(const Value: Integer);
begin
  FdDomain.Send(Value);
end;

function TDISEntityTypeMappingNode.GetExtra: Integer;
begin
  Result := FdExtra.Value;
end;

procedure TDISEntityTypeMappingNode.SetExtra(const Value: Integer);
begin
  FdExtra.Send(Value);
end;

function TDISEntityTypeMappingNode.GetKind: Integer;
begin
  Result := FdKind.Value;
end;

procedure TDISEntityTypeMappingNode.SetKind(const Value: Integer);
begin
  FdKind.Send(Value);
end;

function TDISEntityTypeMappingNode.GetSpecific: Integer;
begin
  Result := FdSpecific.Value;
end;

procedure TDISEntityTypeMappingNode.SetSpecific(const Value: Integer);
begin
  FdSpecific.Send(Value);
end;

function TDISEntityTypeMappingNode.GetSubcategory: Integer;
begin
  Result := FdSubcategory.Value;
end;

procedure TDISEntityTypeMappingNode.SetSubcategory(const Value: Integer);
begin
  FdSubcategory.Send(Value);
end;

{$endif read_implementation}