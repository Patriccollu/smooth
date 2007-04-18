 /* The smooth Class Library
  * Copyright (C) 1998-2007 Robert Kausch <robert.kausch@gmx.net>
  *
  * This library is free software; you can redistribute it and/or
  * modify it under the terms of "The Artistic License, Version 2.0".
  *
  * THIS PACKAGE IS PROVIDED "AS IS" AND WITHOUT ANY EXPRESS OR
  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE. */

#include <smooth/system/system.h>
#include <smooth/version.h>

#include <shlobj.h>

S::Int S::System::System::nextGUID	= 0;

S::System::System::System()
{
}

S::System::System::System(const System &)
{
}

S::Int S::System::System::RequestGUID()
{
	return nextGUID++;
}

S::String S::System::System::GetVersionString()
{
	return SMOOTH_VERSION;
}

S::String S::System::System::GetAPIVersion()
{
	return SMOOTH_APIVERSION;
}

S::String S::System::System::GetWindowsRootDirectory()
{
	String		 windowsDir;

	if (Setup::enableUnicode)
	{
		wchar_t	*bufferw = new wchar_t [MAX_PATH];

		GetWindowsDirectoryW(bufferw, MAX_PATH);

		windowsDir = bufferw;

		delete [] bufferw;
	}
	else
	{
		char	*buffera = new char [MAX_PATH];

		GetWindowsDirectoryA(buffera, MAX_PATH);

		windowsDir = buffera;

		delete [] buffera;
	}

	if (windowsDir[windowsDir.Length() - 1] != '\\') windowsDir.Append("\\");

	return windowsDir;
}

S::String S::System::System::GetProgramFilesDirectory()
{
	String	 programsDir;
	HKEY	 currentVersion;

	if (RegOpenKeyExA(HKEY_LOCAL_MACHINE, "Software\\Microsoft\\Windows\\CurrentVersion", 0, KEY_QUERY_VALUE, &currentVersion) == ERROR_SUCCESS)
	{
		// We need to use the ANSI version of RegQueryValueEx, because
		// the Unicode version is not compatible with MSLU.

		DWORD	 size = MAX_PATH;
		char	*buffer = new char [size];

		RegQueryValueExA(currentVersion, String("ProgramFilesDir"), 0, NIL, (BYTE *) buffer, &size);

		programsDir = buffer;

		delete [] buffer;

		RegCloseKey(currentVersion);
	}

	if (programsDir == NIL)
	{
		// Failed to get the program files directory from the registry.
		// Get the directory name from the environment variable.

		if (Setup::enableUnicode)
		{
			wchar_t	*bufferw = new wchar_t [MAX_PATH];

			ExpandEnvironmentStringsW(String("%ProgramFiles%"), bufferw, MAX_PATH);

			programsDir = bufferw;

			delete [] bufferw;
		}
		else
		{
			char	*buffera = new char [MAX_PATH];

			ExpandEnvironmentStringsA(String("%ProgramFiles%"), buffera, MAX_PATH);

			programsDir = buffera;

			delete [] buffera;
		}
	}

	if (programsDir[programsDir.Length() - 1] != '\\') programsDir.Append("\\");

	return programsDir;
}

S::String S::System::System::GetApplicationDataDirectory()
{
	String		 configDir;
	ITEMIDLIST	*idlist;

	SHGetSpecialFolderLocation(NIL, CSIDL_APPDATA, &idlist);

	if (Setup::enableUnicode)
	{
		wchar_t	*bufferw = new wchar_t [MAX_PATH];

		SHGetPathFromIDListW(idlist, bufferw);

		configDir = bufferw;

		delete [] bufferw;
	}
	else
	{
		char	*buffera = new char [MAX_PATH];

		SHGetPathFromIDListA(idlist, buffera);

		configDir = buffera;

		delete [] buffera;
	}

	CoTaskMemFree(idlist);

	if (configDir[configDir.Length() - 1] != '\\') configDir.Append("\\");
	if (configDir == "\\") configDir = "";

	return configDir;
}

S::String S::System::System::GetPersonalFilesDirectory()
{
	String		 personalDir;
	ITEMIDLIST	*idlist;

	SHGetSpecialFolderLocation(NIL, CSIDL_PERSONAL, &idlist);

	if (Setup::enableUnicode)
	{
		wchar_t	*bufferw = new wchar_t [MAX_PATH];

		SHGetPathFromIDListW(idlist, bufferw);

		personalDir = bufferw;

		delete [] bufferw;
	}
	else
	{
		char	*buffera = new char [MAX_PATH];

		SHGetPathFromIDListA(idlist, buffera);

		personalDir = buffera;

		delete [] buffera;
	}

	CoTaskMemFree(idlist);

	if (personalDir[personalDir.Length() - 1] != '\\') personalDir.Append("\\");
	if (personalDir == "\\") personalDir = "C:\\";

	return personalDir;
}

S::String S::System::System::GetTempDirectory()
{
	// We need to use the ANSI version of GetTempPath, because
	// the Unicode version is not compatible with MSLU.

	String	 tempDir;
	char	*buffera = new char [MAX_PATH];

	GetTempPathA(MAX_PATH, buffera);

	tempDir = buffera;

	delete [] buffera;

	if (tempDir[tempDir.Length() - 1] != '\\') tempDir.Append("\\");

	return tempDir;
}
