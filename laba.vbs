Dim s, FSO, F, Code1, Path, a,ff,sf

do
	Set FSO = WScript.CreateObject("Scripting.FileSystemObject")
	Set WshShell = WScript.CreateObject("WScript.Shell")

	WScript.StdOut.WriteLine "����:"
	WScript.StdOut.WriteLine "---------------------"
	WScript.StdOut.WriteLine "1. ���������� �� ������."
	WScript.StdOut.WriteLine "2. �������� �������� ������ ��������� ����������"
	WScript.StdOut.WriteLine "3. �������� ������ ��� ��������� ����������� �������� ����� � ��������� ��� �� ������� ����."
	WScript.StdOut.WriteLine "4. �����."
	WScript.StdOut.Write "�������� ����� ����:"
	s=WScript.StdIn.ReadLine
	'....
	if(s="1") Then
		WScript.StdOut.WriteLine "�����: �������� ������ ��������, ���-11"

	elseif(s="2") Then
	WScript.StdOut.Write "������� ���������� ����� "
        WScript.StdOut.Write " >> "
        ff = WScript.StdIn.ReadLine
        WScript.StdOut.Write "������� ������������ �����, � ������� ���������� �����"
        WScript.StdOut.Write " >> "
        sf = WScript.StdIn.ReadLine
        	WshShell.Run "cmd.exe /c D:\OC2\zad1.cmd", 0, false

		
	
	elseif(s="3") Then
	set WshShell = WScript.CreateObject("WScript.Shell" )
set oShellLink = WshShell.CreateShortcut("D:\OC2\PAP.lnk" )
oShellLink.TargetPath = "D:\OC2\zad1" ' <- ����� ��� ������
oShellLink.Arguments = "https://imya_servera.jnlp" ' <- ����� ��������� �������
oShellLink.WindowStyle = 1
oShellLink.Description = "Shortcut Script"
oShellLink.WorkingDirectory = "c:\windows\system32\"
oShellLink.Save

	End if

loop until (s="4")
