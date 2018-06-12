--- src/nuspell/dictionary.hxx.orig	2018-06-13 00:10:53.396428000 +0200
+++ src/nuspell/dictionary.hxx	2018-06-13 00:11:16.140737000 +0200
@@ -82,9 +82,10 @@
 	 * @return if found, root word + prefix
 	 */
 	template <Affixing_Mode m = FULL_WORD, class CharT>
-	auto
-	strip_prefix_only(std::basic_string<CharT>& s) const -> boost::optional<
-	    std::tuple<const string&, const Flag_Set&, const Prefix<CharT>&>>;
+	auto strip_prefix_only(std::basic_string<CharT>& s) const
+	    -> boost::optional<
+	        std::tuple<std::basic_string<CharT>, const Flag_Set&,
+	                   const Prefix<CharT>&>>;
 
 	/**
 	 * @brief strip_suffix_only
@@ -92,9 +93,10 @@
 	 * @return if found, root word + suffix
 	 */
 	template <Affixing_Mode m = FULL_WORD, class CharT>
-	auto
-	strip_suffix_only(std::basic_string<CharT>& s) const -> boost::optional<
-	    std::tuple<const string&, const Flag_Set&, const Suffix<CharT>&>>;
+	auto strip_suffix_only(std::basic_string<CharT>& s) const
+	    -> boost::optional<
+	        std::tuple<std::basic_string<CharT>, const Flag_Set&,
+	                   const Suffix<CharT>&>>;
 
 	/**
 	 * @brief strip_prefix_then_suffix
@@ -108,15 +110,15 @@
 	template <Affixing_Mode m = FULL_WORD, class CharT>
 	auto strip_prefix_then_suffix(std::basic_string<CharT>& s) const
 	    -> boost::optional<
-	        std::tuple<const string&, const Flag_Set&, const Suffix<CharT>&,
-	                   const Prefix<CharT>&>>;
+	        std::tuple<std::basic_string<CharT>, const Flag_Set&,
+	                   const Suffix<CharT>&, const Prefix<CharT>&>>;
 
 	template <Affixing_Mode m, class CharT>
 	auto strip_pfx_then_sfx_2(const Prefix<CharT>& pe,
 	                          std::basic_string<CharT>& s) const
 	    -> boost::optional<
-	        std::tuple<const string&, const Flag_Set&, const Suffix<CharT>&,
-	                   const Prefix<CharT>&>>;
+	        std::tuple<std::basic_string<CharT>, const Flag_Set&,
+	                   const Suffix<CharT>&, const Prefix<CharT>&>>;
 
 	/**
 	 * @brief strip_suffix_then_prefix
@@ -130,98 +132,110 @@
 	template <Affixing_Mode m = FULL_WORD, class CharT>
 	auto strip_suffix_then_prefix(std::basic_string<CharT>& s) const
 	    -> boost::optional<
-	        std::tuple<const string&, const Flag_Set&, const Prefix<CharT>&,
-	                   const Suffix<CharT>&>>;
+	        std::tuple<std::basic_string<CharT>, const Flag_Set&,
+	                   const Prefix<CharT>&, const Suffix<CharT>&>>;
 
 	template <Affixing_Mode m, class CharT>
 	auto strip_sfx_then_pfx_2(const Suffix<CharT>& se,
 	                          std::basic_string<CharT>& s) const
 	    -> boost::optional<
-	        std::tuple<const string&, const Flag_Set&, const Prefix<CharT>&,
-	                   const Suffix<CharT>&>>;
+	        std::tuple<std::basic_string<CharT>, const Flag_Set&,
+	                   const Prefix<CharT>&, const Suffix<CharT>&>>;
 
 	template <Affixing_Mode m = FULL_WORD, class CharT>
 	auto strip_suffix_then_suffix(std::basic_string<CharT>& s) const
 	    -> boost::optional<
-	        std::tuple<const string&, const Flag_Set&, const Suffix<CharT>&,
-	                   const Suffix<CharT>&>>;
+	        std::tuple<std::basic_string<CharT>, const Flag_Set&,
+	                   const Suffix<CharT>&, const Suffix<CharT>&>>;
 
 	template <Affixing_Mode m, class CharT>
 	auto strip_sfx_then_sfx_2(const Suffix<CharT>& se1,
 	                          std::basic_string<CharT>& s) const
 	    -> boost::optional<
-	        std::tuple<const string&, const Flag_Set&, const Suffix<CharT>&,
-	                   const Suffix<CharT>&>>;
+	        std::tuple<std::basic_string<CharT>, const Flag_Set&,
+	                   const Suffix<CharT>&, const Suffix<CharT>&>>;
 
 	template <Affixing_Mode m = FULL_WORD, class CharT>
 	auto strip_prefix_then_prefix(std::basic_string<CharT>& s) const
 	    -> boost::optional<
-	        std::tuple<const string&, const Flag_Set&, const Prefix<CharT>&,
-	                   const Prefix<CharT>&>>;
+	        std::tuple<std::basic_string<CharT>, const Flag_Set&,
+	                   const Prefix<CharT>&, const Prefix<CharT>&>>;
 
 	template <Affixing_Mode m, class CharT>
 	auto strip_pfx_then_pfx_2(const Prefix<CharT>& pe1,
 	                          std::basic_string<CharT>& s) const
 	    -> boost::optional<
-	        std::tuple<const string&, const Flag_Set&, const Prefix<CharT>&,
-	                   const Prefix<CharT>&>>;
+	        std::tuple<std::basic_string<CharT>, const Flag_Set&,
+	                   const Prefix<CharT>&, const Prefix<CharT>&>>;
 
 	template <Affixing_Mode m = FULL_WORD, class CharT>
 	auto strip_prefix_then_2_suffixes(std::basic_string<CharT>& s) const
-	    -> boost::optional<std::tuple<const string&, const Flag_Set&>>;
+	    -> boost::optional<
+	        std::tuple<std::basic_string<CharT>, const Flag_Set&>>;
 
 	template <Affixing_Mode m, class CharT>
 	auto strip_pfx_2_sfx_3(const Prefix<CharT>& pe1,
 	                       const Suffix<CharT>& se1,
 	                       std::basic_string<CharT>& s) const
-	    -> boost::optional<std::tuple<const string&, const Flag_Set&>>;
+	    -> boost::optional<
+	        std::tuple<std::basic_string<CharT>, const Flag_Set&>>;
 
 	template <Affixing_Mode m = FULL_WORD, class CharT>
 	auto strip_suffix_prefix_suffix(std::basic_string<CharT>& s) const
-	    -> boost::optional<std::tuple<const string&, const Flag_Set&>>;
+	    -> boost::optional<
+	        std::tuple<std::basic_string<CharT>, const Flag_Set&>>;
 
 	template <Affixing_Mode m, class CharT>
 	auto strip_s_p_s_3(const Suffix<CharT>& se1, const Prefix<CharT>& pe1,
 	                   std::basic_string<CharT>& word) const
-	    -> boost::optional<std::tuple<const string&, const Flag_Set&>>;
+	    -> boost::optional<
+	        std::tuple<std::basic_string<CharT>, const Flag_Set&>>;
 
 	template <Affixing_Mode m = FULL_WORD, class CharT>
 	auto strip_2_suffixes_then_prefix(std::basic_string<CharT>& s) const
-	    -> boost::optional<std::tuple<const string&, const Flag_Set&>>;
+	    -> boost::optional<
+	        std::tuple<std::basic_string<CharT>, const Flag_Set&>>;
 
 	template <Affixing_Mode m, class CharT>
 	auto strip_2_sfx_pfx_3(const Suffix<CharT>& se1,
 	                       const Suffix<CharT>& se2,
 	                       std::basic_string<CharT>& word) const
-	    -> boost::optional<std::tuple<const string&, const Flag_Set&>>;
+	    -> boost::optional<
+	        std::tuple<std::basic_string<CharT>, const Flag_Set&>>;
 
 	template <Affixing_Mode m = FULL_WORD, class CharT>
 	auto strip_suffix_then_2_prefixes(std::basic_string<CharT>& s) const
-	    -> boost::optional<std::tuple<const string&, const Flag_Set&>>;
+	    -> boost::optional<
+	        std::tuple<std::basic_string<CharT>, const Flag_Set&>>;
 
 	template <Affixing_Mode m, class CharT>
 	auto strip_sfx_2_pfx_3(const Suffix<CharT>& se1,
 	                       const Prefix<CharT>& pe1,
 	                       std::basic_string<CharT>& s) const
-	    -> boost::optional<std::tuple<const string&, const Flag_Set&>>;
+	    -> boost::optional<
+	        std::tuple<std::basic_string<CharT>, const Flag_Set&>>;
 
 	template <Affixing_Mode m = FULL_WORD, class CharT>
 	auto strip_prefix_suffix_prefix(std::basic_string<CharT>& word) const
-	    -> boost::optional<std::tuple<const string&, const Flag_Set&>>;
+	    -> boost::optional<
+	        std::tuple<std::basic_string<CharT>, const Flag_Set&>>;
 
 	template <Affixing_Mode m, class CharT>
 	auto strip_p_s_p_3(const Prefix<CharT>& pe1, const Suffix<CharT>& se1,
 	                   std::basic_string<CharT>& word) const
-	    -> boost::optional<std::tuple<const string&, const Flag_Set&>>;
+	    -> boost::optional<
+	        std::tuple<std::basic_string<CharT>, const Flag_Set&>>;
 
 	template <Affixing_Mode m = FULL_WORD, class CharT>
 	auto strip_2_prefixes_then_suffix(std::basic_string<CharT>& word) const
-	    -> boost::optional<std::tuple<const string&, const Flag_Set&>>;
+	    -> boost::optional<
+	        std::tuple<std::basic_string<CharT>, const Flag_Set&>>;
 	template <Affixing_Mode m, class CharT>
 	auto strip_2_pfx_sfx_3(const Prefix<CharT>& pe1,
 	                       const Prefix<CharT>& pe2,
 	                       std::basic_string<CharT>& word) const
-	    -> boost::optional<std::tuple<const string&, const Flag_Set&>>;
+	    -> boost::optional<
+	        std::tuple<std::basic_string<CharT>, const Flag_Set&>>;
 
       public:
 	Dictionary()
