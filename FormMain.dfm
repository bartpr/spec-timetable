object FormGUI: TFormGUI
  Left = 768
  Top = 129
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 'Timetable'
  ClientHeight = 360
  ClientWidth = 480
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object PageControl1: TPageControl
    Left = 0
    Top = 0
    Width = 480
    Height = 360
    ActivePage = TabSheet2
    TabIndex = 1
    TabOrder = 0
    object TabSheet1: TTabSheet
      Caption = 'Main'
      object Label1: TLabel
        Left = 8
        Top = 8
        Width = 65
        Height = 13
        Caption = 'Working days'
      end
      object Label2: TLabel
        Left = 8
        Top = 56
        Width = 77
        Height = 13
        Caption = 'Lessons per day'
      end
      object CSpinEdit1: TCSpinEdit
        Left = 16
        Top = 24
        Width = 65
        Height = 22
        MaxValue = 7
        MinValue = 1
        TabOrder = 0
      end
      object CSpinEdit2: TCSpinEdit
        Left = 16
        Top = 72
        Width = 65
        Height = 22
        MaxValue = 50
        MinValue = 1
        TabOrder = 1
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'Classrooms'
      ImageIndex = 1
      object LClassrooms: TListBox
        Left = 0
        Top = 0
        Width = 472
        Height = 300
        ItemHeight = 13
        TabOrder = 0
      end
      object Button1: TButton
        Left = 0
        Top = 305
        Width = 65
        Height = 25
        Caption = 'Add'
        TabOrder = 1
        OnClick = Button1Click
      end
      object Button2: TButton
        Left = 72
        Top = 305
        Width = 65
        Height = 25
        Caption = 'Rename'
        TabOrder = 2
      end
      object Button3: TButton
        Left = 144
        Top = 305
        Width = 65
        Height = 25
        Caption = 'Remove'
        TabOrder = 3
      end
    end
    object TabSheet3: TTabSheet
      Caption = 'Subjects'
      ImageIndex = 2
      object Label5: TLabel
        Left = 8
        Top = 4
        Width = 41
        Height = 13
        Caption = 'Subjects'
      end
      object Label6: TLabel
        Left = 239
        Top = 4
        Width = 70
        Height = 13
        Caption = 'Classroom filter'
      end
      object ListBox2: TListBox
        Left = 0
        Top = 24
        Width = 236
        Height = 276
        ItemHeight = 13
        TabOrder = 0
      end
      object ListBox5: TListBox
        Left = 231
        Top = 24
        Width = 241
        Height = 276
        ItemHeight = 13
        TabOrder = 1
      end
      object Button4: TButton
        Left = 0
        Top = 305
        Width = 65
        Height = 25
        Caption = 'Add'
        TabOrder = 2
      end
      object Button5: TButton
        Left = 72
        Top = 305
        Width = 65
        Height = 25
        Caption = 'Rename'
        TabOrder = 3
      end
      object Button6: TButton
        Left = 144
        Top = 305
        Width = 65
        Height = 25
        Caption = 'Remove'
        TabOrder = 4
      end
      object Button13: TButton
        Left = 231
        Top = 305
        Width = 65
        Height = 25
        Caption = 'Add'
        TabOrder = 5
      end
      object Button14: TButton
        Left = 303
        Top = 305
        Width = 65
        Height = 25
        Caption = 'Rename'
        TabOrder = 6
      end
      object Button15: TButton
        Left = 375
        Top = 305
        Width = 65
        Height = 25
        Caption = 'Remove'
        TabOrder = 7
      end
      object RadioButton1: TRadioButton
        Left = 347
        Top = 3
        Width = 62
        Height = 17
        Caption = 'Whitelist'
        TabOrder = 8
      end
      object RadioButton2: TRadioButton
        Left = 411
        Top = 3
        Width = 62
        Height = 17
        Caption = 'Blacklist'
        TabOrder = 9
      end
    end
    object TabSheet4: TTabSheet
      Caption = 'Teachers'
      ImageIndex = 3
      object Label3: TLabel
        Left = 8
        Top = 4
        Width = 45
        Height = 13
        Caption = 'Teachers'
      end
      object Label4: TLabel
        Left = 239
        Top = 4
        Width = 83
        Height = 13
        Caption = 'Subjects teached'
      end
      object ListBox3: TListBox
        Left = 0
        Top = 24
        Width = 236
        Height = 276
        ItemHeight = 13
        TabOrder = 0
      end
      object Button7: TButton
        Left = 0
        Top = 305
        Width = 65
        Height = 25
        Caption = 'Add'
        TabOrder = 1
      end
      object Button8: TButton
        Left = 72
        Top = 305
        Width = 65
        Height = 25
        Caption = 'Rename'
        TabOrder = 2
      end
      object Button9: TButton
        Left = 144
        Top = 305
        Width = 65
        Height = 25
        Caption = 'Remove'
        TabOrder = 3
      end
      object Button10: TButton
        Left = 231
        Top = 305
        Width = 65
        Height = 25
        Caption = 'Add'
        TabOrder = 4
      end
      object Button11: TButton
        Left = 303
        Top = 305
        Width = 65
        Height = 25
        Caption = 'Rename'
        TabOrder = 5
      end
      object ListBox4: TListBox
        Left = 231
        Top = 24
        Width = 241
        Height = 276
        ItemHeight = 13
        TabOrder = 6
      end
      object Button12: TButton
        Left = 375
        Top = 305
        Width = 65
        Height = 25
        Caption = 'Remove'
        TabOrder = 7
      end
    end
    object TabSheet5: TTabSheet
      Caption = 'Classes'
      ImageIndex = 4
    end
  end
  object MainMenu1: TMainMenu
    Left = 448
    object File1: TMenuItem
      Caption = '&File'
      object Newproject1: TMenuItem
        Caption = '&New project'
        ShortCut = 16462
      end
      object Loadproject1: TMenuItem
        Caption = '&Load project'
        ShortCut = 16460
      end
      object Saveproject1: TMenuItem
        Caption = '&Save project'
        ShortCut = 16467
      end
      object Exit1: TMenuItem
        Caption = '-'
      end
      object Exit2: TMenuItem
        Caption = 'E&xit'
      end
    end
    object Generate1: TMenuItem
      Caption = '&Generate'
    end
    object Help1: TMenuItem
      Caption = '&Help'
      object About1: TMenuItem
        Caption = 'About'
      end
    end
  end
end
