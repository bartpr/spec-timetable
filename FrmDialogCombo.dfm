object FormDialogCombo: TFormDialogCombo
  Left = 467
  Top = 323
  BorderStyle = bsDialog
  ClientHeight = 96
  ClientWidth = 320
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = False
  OnClose = FormClose
  OnKeyDown = FormKeyDown
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Button1: TButton
    Left = 88
    Top = 56
    Width = 65
    Height = 25
    Caption = '&OK'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 160
    Top = 56
    Width = 65
    Height = 25
    Caption = '&Cancel'
    TabOrder = 1
    OnClick = Button2Click
  end
  object ComboBox1: TComboBox
    Left = 16
    Top = 16
    Width = 289
    Height = 21
    ItemHeight = 13
    Sorted = True
    TabOrder = 2
    OnChange = ComboBox1Change
    OnKeyDown = ComboBox1KeyDown
  end
end
