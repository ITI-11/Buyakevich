Dim s, FSO, F, Code1, Path, a,ff,sf

do
	Set FSO = WScript.CreateObject("Scripting.FileSystemObject")
	Set WshShell = WScript.CreateObject("WScript.Shell")

	WScript.StdOut.WriteLine "МЕНЮ:"
	WScript.StdOut.WriteLine "---------------------"
	WScript.StdOut.WriteLine "1. ИНФОРМАЦИЯ ОБ АВТОРЕ."
	WScript.StdOut.WriteLine "2. УДАЛЕНИЕ ЗАДАННЫХ ФАЙЛОВ ЗАДАННОГО РАЗРЕШЕНИЯ"
	WScript.StdOut.WriteLine "3. Создание ярлыка для просмотра содержимого заданной папки и помещение его на рабочий стол."
	WScript.StdOut.WriteLine "4. ВЫХОД."
	WScript.StdOut.Write "Выберите пункт меню:"
	s=WScript.StdIn.ReadLine
	'....
	if(s="1") Then
		WScript.StdOut.WriteLine "Автор: Буякевич Данила Олегович, ИТИ-11"

	elseif(s="2") Then
	WScript.StdOut.Write "Введите расширение файла "
        WScript.StdOut.Write " >> "
        ff = WScript.StdIn.ReadLine
        WScript.StdOut.Write "Введите расположение папки, в которой содержатся файлы"
        WScript.StdOut.Write " >> "
        sf = WScript.StdIn.ReadLine
        	WshShell.Run "cmd.exe /c D:\OC2\zad1.cmd", 0, false

		
	
	elseif(s="3") Then
	set WshShell = WScript.CreateObject("WScript.Shell" )
set oShellLink = WshShell.CreateShortcut("D:\OC2\PAP.lnk" )
oShellLink.TargetPath = "D:\OC2\zad1" ' <- Здесь сам объект
oShellLink.Arguments = "https://imya_servera.jnlp" ' <- Здесь аргументы запуска
oShellLink.WindowStyle = 1
oShellLink.Description = "Shortcut Script"
oShellLink.WorkingDirectory = "c:\windows\system32\"
oShellLink.Save

	End if

loop until (s="4")
