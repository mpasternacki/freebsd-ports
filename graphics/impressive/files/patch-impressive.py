--- impressive.py.orig	2015-06-03 14:12:05 UTC
+++ impressive.py
@@ -334,7 +334,7 @@ class Platform_PyGame(object):
 
     def LoadOpenGL(self):
         try:
-            sdl = CDLL(ctypes.util.find_library("SDL") or "SDL", RTLD_GLOBAL)
+            sdl = CDLL(ctypes.util.find_library("SDL-1.2") or "SDL", RTLD_GLOBAL)
             get_proc_address = CFUNCTYPE(c_void_p, c_char_p)(('SDL_GL_GetProcAddress', sdl))
         except OSError:
             raise ImportError("failed to load the SDL library")
