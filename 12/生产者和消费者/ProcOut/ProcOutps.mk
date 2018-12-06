
ProcOutps.dll: dlldata.obj ProcOut_p.obj ProcOut_i.obj
	link /dll /out:ProcOutps.dll /def:ProcOutps.def /entry:DllMain dlldata.obj ProcOut_p.obj ProcOut_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del ProcOutps.dll
	@del ProcOutps.lib
	@del ProcOutps.exp
	@del dlldata.obj
	@del ProcOut_p.obj
	@del ProcOut_i.obj
