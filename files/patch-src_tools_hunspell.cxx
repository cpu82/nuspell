--- src/tools/hunspell.cxx.orig	2018-06-13 20:45:09 UTC
+++ src/tools/hunspell.cxx
@@ -117,29 +117,23 @@
 #include "../parsers/odfparser.hxx"
 #include "../parsers/noparser.hxx"
 
-#define LIBDIR                \
-  "/usr/share/hunspell:"      \
-  "/usr/share/myspell:"       \
-  "/usr/share/myspell/dicts:" \
+#define LIBDIR                      \
+  "%%PREFIX%%/share/hunspell:"      \
+  "%%PREFIX%%/share/myspell:"       \
+  "%%PREFIX%%/share/myspell/dicts:" \
   "/Library/Spelling"
-#define USEROOODIR {                  \
-  ".openoffice.org/3/user/wordbook", \
-  ".openoffice.org2/user/wordbook",  \
-  ".openoffice.org2.0/user/wordbook",\
+#define USEROOODIR {                 \
+  ".openoffice.org/3/user/wordbook"  \
+  ".openoffice.org2/user/wordbook"   \
+  ".openoffice.org2.0/user/wordbook" \
   "Library/Spelling" }
-#define OOODIR                                       \
-  "/opt/openoffice.org/basis3.0/share/dict/ooo:"     \
-  "/usr/lib/openoffice.org/basis3.0/share/dict/ooo:" \
-  "/opt/openoffice.org2.4/share/dict/ooo:"           \
-  "/usr/lib/openoffice.org2.4/share/dict/ooo:"       \
-  "/opt/openoffice.org2.3/share/dict/ooo:"           \
-  "/usr/lib/openoffice.org2.3/share/dict/ooo:"       \
-  "/opt/openoffice.org2.2/share/dict/ooo:"           \
-  "/usr/lib/openoffice.org2.2/share/dict/ooo:"       \
-  "/opt/openoffice.org2.1/share/dict/ooo:"           \
-  "/usr/lib/openoffice.org2.1/share/dict/ooo:"       \
-  "/opt/openoffice.org2.0/share/dict/ooo:"           \
-  "/usr/lib/openoffice.org2.0/share/dict/ooo"
+#define OOODIR                                         \
+  "%%PREFIX%%/openoffice.org/basis3.0/share/dict/ooo:" \
+  "%%PREFIX%%/openoffice.org2.4/share/dict/ooo:"       \
+  "%%PREFIX%%/openoffice.org2.3/share/dict/ooo:"       \
+  "%%PREFIX%%/openoffice.org2.2/share/dict/ooo:"       \
+  "%%PREFIX%%/openoffice.org2.1/share/dict/ooo:"       \
+  "%%PREFIX%%/openoffice.org2.0/share/dict/ooo"
 #define HOME getenv("HOME")
 #define DICBASENAME ".hunspell_"
 #define LOGFILE "/tmp/hunspell.log"
