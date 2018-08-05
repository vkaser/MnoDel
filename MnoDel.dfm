object Form1: TForm1
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = #1052#1085#1086#1044#1077#1083
  ClientHeight = 146
  ClientWidth = 371
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  OnActivate = FormActivate
  PixelsPerInch = 96
  TextHeight = 13
  object Button1: TButton
    Left = 0
    Top = 0
    Width = 186
    Height = 84
    Align = alLeft
    Caption = #1059#1052#1053#1054#1046#1045#1053#1048#1045
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBackground
    Font.Height = -24
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 185
    Top = 0
    Width = 186
    Height = 84
    Align = alRight
    Caption = #1044#1045#1051#1045#1053#1048#1045
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -24
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    OnClick = Button2Click
  end
  object Panel1: TPanel
    Left = 0
    Top = 84
    Width = 371
    Height = 62
    Align = alBottom
    ParentBackground = False
    TabOrder = 2
    object Label1: TLabel
      Left = 16
      Top = 17
      Width = 255
      Height = 23
      Caption = #1047#1072#1076#1072#1081#1090#1077' '#1084#1072#1082#1089#1080#1084#1072#1083#1100#1085#1086#1077' '#1095#1080#1089#1083#1086
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBtnText
      Font.Height = -21
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentFont = False
    end
    object Edit1: TEdit
      Left = 285
      Top = 16
      Width = 65
      Height = 27
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      OnKeyPress = Edit1KeyPress
    end
  end
end
