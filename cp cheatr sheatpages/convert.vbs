Option Explicit

Dim fso, word, folder, pdfFolder
Dim file, doc, pdfPath

Set fso = CreateObject("Scripting.FileSystemObject")
Set word = CreateObject("Word.Application")

word.Visible = False
word.DisplayAlerts = 0

folder = fso.GetParentFolderName(WScript.ScriptFullName)
pdfFolder = folder & "\Final PDF"

If Not fso.FolderExists(pdfFolder) Then
    fso.CreateFolder pdfFolder
End If

For Each file In fso.GetFolder(folder).Files

    ' Only process real DOCX files (skip Word temp files)
    If LCase(fso.GetExtensionName(file.Name)) = "docx" _
       And Left(file.Name,2) <> "~$" Then

        On Error Resume Next

        Set doc = word.Documents.Open(file.Path, False, True)

        If Err.Number = 0 Then

            pdfPath = pdfFolder & "\" & fso.GetBaseName(file.Name) & ".pdf"

            doc.ExportAsFixedFormat pdfPath, 17
            doc.Close False

        End If

        Err.Clear
        On Error GoTo 0

    End If

Next

word.Quit False

Set word = Nothing
Set fso = Nothing

MsgBox "Finished! All valid DOCX files have been converted to PDF.", vbInformation