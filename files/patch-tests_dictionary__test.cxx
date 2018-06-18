--- tests/dictionary_test.cxx.orig	2018-06-18 14:00:54.000000000 +0200
+++ tests/dictionary_test.cxx	2018-06-18 15:06:19.395406000 +0200
@@ -54,9 +54,15 @@
 	auto d = Dictionary();
 	d.set_encoding_and_language("UTF-8");
 
-	d.words.emplace("berry", u"T");
-	d.words.emplace("May", u"T");
-	d.words.emplace("vary", u"");
+	d.words.emplace(std::piecewise_construct,
+			std::forward_as_tuple("berry"),
+			std::forward_as_tuple(u"T"));
+	d.words.emplace(std::piecewise_construct,
+			std::forward_as_tuple("May"),
+			std::forward_as_tuple(u"T"));
+	d.words.emplace(std::piecewise_construct,
+			std::forward_as_tuple("vary"),
+			std::forward_as_tuple(u""));
 
 	d.structures.suffixes.emplace(u'T', true, "y"s, "ies"s, Flag_Set(),
 	                              ".[^aeiou]y"s);
@@ -77,8 +83,12 @@
 	auto d = Dictionary();
 	d.set_encoding_and_language("UTF-8");
 
-	d.words.emplace("user", u"");
-	d.words.emplace("interface", u"");
+	d.words.emplace(std::piecewise_construct,
+		std::forward_as_tuple("user"),
+		std::forward_as_tuple(u""));
+	d.words.emplace(std::piecewise_construct,
+		std::forward_as_tuple("interface"),
+		std::forward_as_tuple(u""));
 
 	d.structures.break_table = {"-"};
 
