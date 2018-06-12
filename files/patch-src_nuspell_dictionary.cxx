--- src/nuspell/dictionary.cxx.orig	2018-06-13 00:10:42.597116000 +0200
+++ src/nuspell/dictionary.cxx	2018-06-13 00:11:16.140681000 +0200
@@ -570,8 +570,8 @@
 
 template <Affixing_Mode m, class CharT>
 auto Dictionary::strip_prefix_only(std::basic_string<CharT>& word) const
-    -> boost::optional<
-        std::tuple<const string&, const Flag_Set&, const Prefix<CharT>&>>
+    -> boost::optional<std::tuple<std::basic_string<CharT>, const Flag_Set&,
+                                  const Prefix<CharT>&>>
 {
 	auto& dic = words;
 	auto& prefixes = get_structures<CharT>().prefixes;
@@ -591,7 +591,7 @@
 			if (!cross_valid_inner_outer(word_flags, e))
 				continue;
 			// needflag check here if needed
-			return {{word_entry.first, word_flags, e}};
+			return {{word, word_flags, e}};
 		}
 	}
 	return {};
@@ -599,8 +599,8 @@
 
 template <Affixing_Mode m, class CharT>
 auto Dictionary::strip_suffix_only(std::basic_string<CharT>& word) const
-    -> boost::optional<
-        std::tuple<const string&, const Flag_Set&, const Suffix<CharT>&>>
+    -> boost::optional<std::tuple<std::basic_string<CharT>, const Flag_Set&,
+                                  const Suffix<CharT>&>>
 {
 	auto& dic = words;
 	auto& suffixes = get_structures<CharT>().suffixes;
@@ -626,7 +626,7 @@
 			    word_flags.contains(compound_onlyin_flag))
 				continue;
 			// needflag check here if needed
-			return {{word_entry.first, word_flags, e}};
+			return {{word, word_flags, e}};
 		}
 	}
 	return {};
@@ -634,7 +634,7 @@
 
 template <Affixing_Mode m, class CharT>
 auto Dictionary::strip_prefix_then_suffix(std::basic_string<CharT>& word) const
-    -> boost::optional<std::tuple<const string&, const Flag_Set&,
+    -> boost::optional<std::tuple<std::basic_string<CharT>, const Flag_Set&,
                                   const Suffix<CharT>&, const Prefix<CharT>&>>
 {
 	auto& prefixes = get_structures<CharT>().prefixes;
@@ -658,7 +658,7 @@
 template <Affixing_Mode m, class CharT>
 auto Dictionary::strip_pfx_then_sfx_2(const Prefix<CharT>& pe,
                                       std::basic_string<CharT>& word) const
-    -> boost::optional<std::tuple<const string&, const Flag_Set&,
+    -> boost::optional<std::tuple<std::basic_string<CharT>, const Flag_Set&,
                                   const Suffix<CharT>&, const Prefix<CharT>&>>
 {
 	auto& dic = words;
@@ -687,7 +687,7 @@
 			    word_flags.contains(compound_onlyin_flag))
 				continue;
 			// needflag check here if needed
-			return {{word_entry.first, word_flags, se, pe}};
+			return {{word, word_flags, se, pe}};
 		}
 	}
 
@@ -696,7 +696,7 @@
 
 template <Affixing_Mode m, class CharT>
 auto Dictionary::strip_suffix_then_prefix(std::basic_string<CharT>& word) const
-    -> boost::optional<std::tuple<const string&, const Flag_Set&,
+    -> boost::optional<std::tuple<std::basic_string<CharT>, const Flag_Set&,
                                   const Prefix<CharT>&, const Suffix<CharT>&>>
 {
 	auto& suffixes = get_structures<CharT>().suffixes;
@@ -720,7 +720,7 @@
 template <Affixing_Mode m, class CharT>
 auto Dictionary::strip_sfx_then_pfx_2(const Suffix<CharT>& se,
                                       std::basic_string<CharT>& word) const
-    -> boost::optional<std::tuple<const string&, const Flag_Set&,
+    -> boost::optional<std::tuple<std::basic_string<CharT>, const Flag_Set&,
                                   const Prefix<CharT>&, const Suffix<CharT>&>>
 {
 	auto& dic = words;
@@ -749,7 +749,7 @@
 			    word_flags.contains(compound_onlyin_flag))
 				continue;
 			// needflag check here if needed
-			return {{word_entry.first, word_flags, pe, se}};
+			return {{word, word_flags, pe, se}};
 		}
 	}
 	return {};
@@ -757,7 +757,7 @@
 
 template <Affixing_Mode m, class CharT>
 auto Dictionary::strip_suffix_then_suffix(std::basic_string<CharT>& word) const
-    -> boost::optional<std::tuple<const string&, const Flag_Set&,
+    -> boost::optional<std::tuple<std::basic_string<CharT>, const Flag_Set&,
                                   const Suffix<CharT>&, const Suffix<CharT>&>>
 {
 	auto& suffixes = get_structures<CharT>().suffixes;
@@ -781,7 +781,7 @@
 template <Affixing_Mode m, class CharT>
 auto Dictionary::strip_sfx_then_sfx_2(const Suffix<CharT>& se1,
                                       std::basic_string<CharT>& word) const
-    -> boost::optional<std::tuple<const string&, const Flag_Set&,
+    -> boost::optional<std::tuple<std::basic_string<CharT>, const Flag_Set&,
                                   const Suffix<CharT>&, const Suffix<CharT>&>>
 {
 
@@ -808,7 +808,7 @@
 			//    word_flags.contains(compound_onlyin_flag))
 			//	continue;
 			// needflag check here if needed
-			return {{word_entry.first, word_flags, se2, se1}};
+			return {{word, word_flags, se2, se1}};
 		}
 	}
 	return {};
@@ -816,7 +816,7 @@
 
 template <Affixing_Mode m, class CharT>
 auto Dictionary::strip_prefix_then_prefix(std::basic_string<CharT>& word) const
-    -> boost::optional<std::tuple<const string&, const Flag_Set&,
+    -> boost::optional<std::tuple<std::basic_string<CharT>, const Flag_Set&,
                                   const Prefix<CharT>&, const Prefix<CharT>&>>
 {
 	auto& prefixes = get_structures<CharT>().prefixes;
@@ -840,7 +840,7 @@
 template <Affixing_Mode m, class CharT>
 auto Dictionary::strip_pfx_then_pfx_2(const Prefix<CharT>& pe1,
                                       std::basic_string<CharT>& word) const
-    -> boost::optional<std::tuple<const string&, const Flag_Set&,
+    -> boost::optional<std::tuple<std::basic_string<CharT>, const Flag_Set&,
                                   const Prefix<CharT>&, const Prefix<CharT>&>>
 {
 	auto& dic = words;
@@ -866,15 +866,16 @@
 			//    word_flags.contains(compound_onlyin_flag))
 			//	continue;
 			// needflag check here if needed
-			return {{word_entry.first, word_flags, pe2, pe1}};
+			return {{word, word_flags, pe2, pe1}};
 		}
 	}
 	return {};
 }
 
 template <Affixing_Mode m, class CharT>
-auto Dictionary::strip_prefix_then_2_suffixes(std::basic_string<CharT>& word)
-    const -> boost::optional<std::tuple<const string&, const Flag_Set&>>
+auto Dictionary::strip_prefix_then_2_suffixes(
+    std::basic_string<CharT>& word) const
+    -> boost::optional<std::tuple<std::basic_string<CharT>, const Flag_Set&>>
 {
 	auto& prefixes = get_structures<CharT>().prefixes;
 	auto& suffixes = get_structures<CharT>().suffixes;
@@ -911,7 +912,7 @@
 auto Dictionary::strip_pfx_2_sfx_3(const Prefix<CharT>& pe1,
                                    const Suffix<CharT>& se1,
                                    std::basic_string<CharT>& word) const
-    -> boost::optional<std::tuple<const string&, const Flag_Set&>>
+    -> boost::optional<std::tuple<std::basic_string<CharT>, const Flag_Set&>>
 {
 	auto& dic = words;
 	auto& suffixes = get_structures<CharT>().suffixes;
@@ -939,7 +940,7 @@
 			//    word_flags.contains(compound_onlyin_flag))
 			//	continue;
 			// needflag check here if needed
-			return {{word_entry.first, word_flags}};
+			return {{word, word_flags}};
 		}
 	}
 
@@ -947,8 +948,9 @@
 }
 
 template <Affixing_Mode m, class CharT>
-auto Dictionary::strip_suffix_prefix_suffix(std::basic_string<CharT>& word)
-    const -> boost::optional<std::tuple<const string&, const Flag_Set&>>
+auto Dictionary::strip_suffix_prefix_suffix(
+    std::basic_string<CharT>& word) const
+    -> boost::optional<std::tuple<std::basic_string<CharT>, const Flag_Set&>>
 {
 	auto& prefixes = get_structures<CharT>().prefixes;
 	auto& suffixes = get_structures<CharT>().suffixes;
@@ -983,7 +985,7 @@
 auto Dictionary::strip_s_p_s_3(const Suffix<CharT>& se1,
                                const Prefix<CharT>& pe1,
                                std::basic_string<CharT>& word) const
-    -> boost::optional<std::tuple<const string&, const Flag_Set&>>
+    -> boost::optional<std::tuple<std::basic_string<CharT>, const Flag_Set&>>
 {
 	auto& dic = words;
 	auto& suffixes = get_structures<CharT>().suffixes;
@@ -1016,7 +1018,7 @@
 			//    word_flags.contains(compound_onlyin_flag))
 			//	continue;
 			// needflag check here if needed
-			return {{word_entry.first, word_flags}};
+			return {{word, word_flags}};
 		}
 	}
 
@@ -1024,8 +1026,9 @@
 }
 
 template <Affixing_Mode m, class CharT>
-auto Dictionary::strip_2_suffixes_then_prefix(std::basic_string<CharT>& word)
-    const -> boost::optional<std::tuple<const string&, const Flag_Set&>>
+auto Dictionary::strip_2_suffixes_then_prefix(
+    std::basic_string<CharT>& word) const
+    -> boost::optional<std::tuple<std::basic_string<CharT>, const Flag_Set&>>
 {
 	auto& suffixes = get_structures<CharT>().suffixes;
 
@@ -1059,7 +1062,7 @@
 auto Dictionary::strip_2_sfx_pfx_3(const Suffix<CharT>& se1,
                                    const Suffix<CharT>& se2,
                                    std::basic_string<CharT>& word) const
-    -> boost::optional<std::tuple<const string&, const Flag_Set&>>
+    -> boost::optional<std::tuple<std::basic_string<CharT>, const Flag_Set&>>
 {
 	auto& dic = words;
 	auto& prefixes = get_structures<CharT>().prefixes;
@@ -1088,7 +1091,7 @@
 			//    word_flags.contains(compound_onlyin_flag))
 			//	continue;
 			// needflag check here if needed
-			return {{word_entry.first, word_flags}};
+			return {{word, word_flags}};
 		}
 	}
 
@@ -1096,8 +1099,9 @@
 }
 
 template <Affixing_Mode m, class CharT>
-auto Dictionary::strip_suffix_then_2_prefixes(std::basic_string<CharT>& word)
-    const -> boost::optional<std::tuple<const string&, const Flag_Set&>>
+auto Dictionary::strip_suffix_then_2_prefixes(
+    std::basic_string<CharT>& word) const
+    -> boost::optional<std::tuple<std::basic_string<CharT>, const Flag_Set&>>
 {
 	auto& prefixes = get_structures<CharT>().prefixes;
 	auto& suffixes = get_structures<CharT>().suffixes;
@@ -1134,7 +1138,7 @@
 auto Dictionary::strip_sfx_2_pfx_3(const Suffix<CharT>& se1,
                                    const Prefix<CharT>& pe1,
                                    std::basic_string<CharT>& word) const
-    -> boost::optional<std::tuple<const string&, const Flag_Set&>>
+    -> boost::optional<std::tuple<std::basic_string<CharT>, const Flag_Set&>>
 {
 	auto& dic = words;
 	auto& prefixes = get_structures<CharT>().prefixes;
@@ -1158,7 +1162,7 @@
 				continue;
 			if (!cross_valid_inner_outer(word_flags, pe2))
 				continue;
-			return {{word_entry.first, word_flags}};
+			return {{word, word_flags}};
 		}
 	}
 
@@ -1166,8 +1170,9 @@
 }
 
 template <Affixing_Mode m, class CharT>
-auto Dictionary::strip_prefix_suffix_prefix(std::basic_string<CharT>& word)
-    const -> boost::optional<std::tuple<const string&, const Flag_Set&>>
+auto Dictionary::strip_prefix_suffix_prefix(
+    std::basic_string<CharT>& word) const
+    -> boost::optional<std::tuple<std::basic_string<CharT>, const Flag_Set&>>
 {
 	auto& prefixes = get_structures<CharT>().prefixes;
 	auto& suffixes = get_structures<CharT>().suffixes;
@@ -1202,7 +1207,7 @@
 auto Dictionary::strip_p_s_p_3(const Prefix<CharT>& pe1,
                                const Suffix<CharT>& se1,
                                std::basic_string<CharT>& word) const
-    -> boost::optional<std::tuple<const string&, const Flag_Set&>>
+    -> boost::optional<std::tuple<std::basic_string<CharT>, const Flag_Set&>>
 {
 	auto& dic = words;
 	auto& prefixes = get_structures<CharT>().prefixes;
@@ -1231,7 +1236,7 @@
 				continue;
 			if (!cross_valid_inner_outer(word_flags, pe2))
 				continue;
-			return {{word_entry.first, word_flags}};
+			return {{word, word_flags}};
 		}
 	}
 
@@ -1239,8 +1244,9 @@
 }
 
 template <Affixing_Mode m, class CharT>
-auto Dictionary::strip_2_prefixes_then_suffix(std::basic_string<CharT>& word)
-    const -> boost::optional<std::tuple<const string&, const Flag_Set&>>
+auto Dictionary::strip_2_prefixes_then_suffix(
+    std::basic_string<CharT>& word) const
+    -> boost::optional<std::tuple<std::basic_string<CharT>, const Flag_Set&>>
 {
 	auto& prefixes = get_structures<CharT>().prefixes;
 
@@ -1274,7 +1280,7 @@
 auto Dictionary::strip_2_pfx_sfx_3(const Prefix<CharT>& pe1,
                                    const Prefix<CharT>& pe2,
                                    std::basic_string<CharT>& word) const
-    -> boost::optional<std::tuple<const string&, const Flag_Set&>>
+    -> boost::optional<std::tuple<std::basic_string<CharT>, const Flag_Set&>>
 {
 	auto& dic = words;
 	auto& suffixes = get_structures<CharT>().suffixes;
@@ -1300,7 +1306,7 @@
 			if (!cross_valid_inner_outer(word_flags, se1))
 				continue;
 			// needflag check here if needed
-			return {{word_entry.first, word_flags}};
+			return {{word, word_flags}};
 		}
 	}
 
