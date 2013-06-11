object FormGUI: TFormGUI
  Left = 211
  Top = 153
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
    ActivePage = TabSheet5
    TabIndex = 4
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
        Value = 5
      end
      object CSpinEdit2: TCSpinEdit
        Left = 16
        Top = 72
        Width = 65
        Height = 22
        MaxValue = 50
        MinValue = 1
        TabOrder = 1
        Value = 14
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
        Sorted = True
        TabOrder = 0
        OnKeyDown = LClassroomsKeyDown
      end
      object BClassroomAdd: TButton
        Left = 0
        Top = 305
        Width = 65
        Height = 25
        Caption = 'Add'
        TabOrder = 1
        OnClick = BClassroomAddClick
      end
      object BClassroomRename: TButton
        Left = 72
        Top = 305
        Width = 65
        Height = 25
        Caption = 'Rename'
        TabOrder = 2
        OnClick = BClassroomRenameClick
      end
      object BClassroomRemove: TButton
        Left = 144
        Top = 305
        Width = 65
        Height = 25
        Caption = 'Remove'
        TabOrder = 3
        OnClick = BClassroomRemoveClick
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
      object LSubjects: TListBox
        Left = 0
        Top = 24
        Width = 236
        Height = 276
        ItemHeight = 13
        Sorted = True
        TabOrder = 0
        OnClick = LSubjectsClick
        OnKeyDown = LSubjectsKeyDown
      end
      object LSubjectFilters: TListBox
        Left = 231
        Top = 24
        Width = 241
        Height = 276
        ItemHeight = 13
        Sorted = True
        TabOrder = 1
        OnKeyDown = LSubjectFiltersKeyDown
      end
      object BSubjectAdd: TButton
        Left = 0
        Top = 305
        Width = 65
        Height = 25
        Caption = 'Add'
        TabOrder = 2
        OnClick = BSubjectAddClick
      end
      object BSubjectRename: TButton
        Left = 72
        Top = 305
        Width = 65
        Height = 25
        Caption = 'Rename'
        TabOrder = 3
        OnClick = BSubjectRenameClick
      end
      object BSubjectRemove: TButton
        Left = 144
        Top = 305
        Width = 65
        Height = 25
        Caption = 'Remove'
        TabOrder = 4
        OnClick = BSubjectRemoveClick
      end
      object BSubjectFilterAdd: TButton
        Left = 231
        Top = 305
        Width = 65
        Height = 25
        Caption = 'Add'
        TabOrder = 5
        OnClick = BSubjectFilterAddClick
      end
      object BSubjectFilterRemove: TButton
        Left = 303
        Top = 305
        Width = 65
        Height = 25
        Caption = 'Remove'
        TabOrder = 6
        OnClick = BSubjectFilterRemoveClick
      end
      object RSubjectFilterWhite: TRadioButton
        Left = 347
        Top = 3
        Width = 62
        Height = 17
        Caption = 'Whitelist'
        TabOrder = 7
        OnClick = RSubjectFilterWhiteClick
      end
      object RSubjectFilterBlack: TRadioButton
        Left = 411
        Top = 3
        Width = 62
        Height = 17
        Caption = 'Blacklist'
        TabOrder = 8
        OnClick = RSubjectFilterBlackClick
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
      object LTeachers: TListBox
        Left = 0
        Top = 24
        Width = 236
        Height = 276
        ItemHeight = 13
        Sorted = True
        TabOrder = 0
        OnClick = LTeachersClick
        OnKeyDown = LTeachersKeyDown
      end
      object BTeacherAdd: TButton
        Left = 0
        Top = 305
        Width = 65
        Height = 25
        Caption = 'Add'
        TabOrder = 1
        OnClick = BTeacherAddClick
      end
      object BTeacherRename: TButton
        Left = 72
        Top = 305
        Width = 65
        Height = 25
        Caption = 'Rename'
        TabOrder = 2
        OnClick = BTeacherRenameClick
      end
      object BTeacherRemove: TButton
        Left = 144
        Top = 305
        Width = 65
        Height = 25
        Caption = 'Remove'
        TabOrder = 3
        OnClick = BTeacherRemoveClick
      end
      object BTeacherSubjectAdd: TButton
        Left = 231
        Top = 305
        Width = 65
        Height = 25
        Caption = 'Add'
        TabOrder = 4
        OnClick = BTeacherSubjectAddClick
      end
      object BTeacherSubjectRemove: TButton
        Left = 303
        Top = 305
        Width = 65
        Height = 25
        Caption = 'Remove'
        TabOrder = 5
        OnClick = BTeacherSubjectRemoveClick
      end
      object LTeacherSubjects: TListBox
        Left = 231
        Top = 24
        Width = 241
        Height = 276
        ItemHeight = 13
        Sorted = True
        TabOrder = 6
        OnKeyDown = LTeacherSubjectsKeyDown
      end
    end
    object TabSheet5: TTabSheet
      Caption = 'Classes'
      ImageIndex = 4
      object Label7: TLabel
        Left = 8
        Top = 4
        Width = 36
        Height = 13
        Caption = 'Classes'
      end
      object Label8: TLabel
        Left = 8
        Top = 170
        Width = 34
        Height = 13
        Caption = 'Groups'
      end
      object Label9: TLabel
        Left = 248
        Top = 2
        Width = 51
        Height = 13
        Caption = 'Subgroups'
      end
      object Label10: TLabel
        Left = 248
        Top = 170
        Width = 41
        Height = 13
        Caption = 'Subjects'
      end
      object LClasses: TListBox
        Left = 0
        Top = 24
        Width = 236
        Height = 110
        ItemHeight = 13
        Sorted = True
        TabOrder = 0
        OnClick = LClassesClick
        OnKeyDown = LClassesKeyDown
      end
      object BClassRename: TButton
        Left = 72
        Top = 139
        Width = 65
        Height = 25
        Caption = 'Rename'
        TabOrder = 1
        OnClick = BClassRenameClick
      end
      object BClassRemove: TButton
        Left = 144
        Top = 139
        Width = 65
        Height = 25
        Caption = 'Remove'
        TabOrder = 2
        OnClick = BClassRemoveClick
      end
      object LClassGroups: TListBox
        Left = 0
        Top = 190
        Width = 236
        Height = 110
        ItemHeight = 13
        Sorted = True
        TabOrder = 3
        OnClick = LClassGroupsClick
        OnKeyDown = LTeachersKeyDown
      end
      object BClassGroupAdd: TButton
        Left = 0
        Top = 305
        Width = 65
        Height = 25
        Caption = 'Add'
        TabOrder = 4
      end
      object BClassGroupRename: TButton
        Left = 72
        Top = 305
        Width = 65
        Height = 25
        Caption = 'Rename'
        TabOrder = 5
        OnClick = BTeacherRenameClick
      end
      object BClassGroupRemove: TButton
        Left = 144
        Top = 305
        Width = 65
        Height = 25
        Caption = 'Remove'
        TabOrder = 6
        OnClick = BTeacherRemoveClick
      end
      object LClassSubgroups: TListBox
        Left = 240
        Top = 22
        Width = 236
        Height = 110
        ItemHeight = 13
        Sorted = True
        TabOrder = 7
        OnClick = LTeachersClick
        OnKeyDown = LTeachersKeyDown
      end
      object BClassSubgroupAdd: TButton
        Left = 240
        Top = 138
        Width = 65
        Height = 25
        Caption = 'Add'
        TabOrder = 8
        OnClick = BTeacherAddClick
      end
      object BClassSubgroupRename: TButton
        Left = 312
        Top = 138
        Width = 65
        Height = 25
        Caption = 'Rename'
        TabOrder = 9
        OnClick = BTeacherRenameClick
      end
      object BClassSubgroupRemove: TButton
        Left = 384
        Top = 138
        Width = 65
        Height = 25
        Caption = 'Remove'
        TabOrder = 10
        OnClick = BTeacherRemoveClick
      end
      object BClassSubjectAdd: TButton
        Left = 240
        Top = 304
        Width = 65
        Height = 25
        Caption = 'Add'
        TabOrder = 11
        OnClick = BTeacherAddClick
      end
      object BClassSubjectRemove: TButton
        Left = 312
        Top = 304
        Width = 65
        Height = 25
        Caption = 'Remove'
        TabOrder = 12
        OnClick = BTeacherRenameClick
      end
      object CmbClassSubjects: TComboBox
        Left = 248
        Top = 208
        Width = 225
        Height = 21
        ItemHeight = 13
        TabOrder = 13
      end
      object CmbClassTeachers: TComboBox
        Left = 247
        Top = 240
        Width = 225
        Height = 21
        ItemHeight = 13
        TabOrder = 14
      end
      object BClassAdd: TButton
        Left = 0
        Top = 139
        Width = 65
        Height = 25
        Caption = 'Add'
        TabOrder = 15
        OnClick = BClassAddClick
      end
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
