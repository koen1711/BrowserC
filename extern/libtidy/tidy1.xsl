<?xml version="1.0"?>
<!--
  For generating the `tidy.1` man page from the
  output of `tidy -xml-help` and `tidy -xml-config`

  (c) 2005-2017 (W3C) MIT, ERCIM, Keio University
  See tidy.h for the copyright notice.

  Written by Jelks Cabaniss and Arnaud Desitter
-->
<xsl:stylesheet version="1.0"
                xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<xsl:strip-space elements="description" />

<xsl:output method="text" />

<!--
  The default template match is to the document passed on the
  command line to the XSLT processor, currently "tidy-help.xml".
  For the detailed config options section however, the template
  match is to the file "tidy-config.xml".  This is captured in
  the $CONFIG variable, declared here. CMAKE configure will
  substitute TIDYCONFIG during the build. Shell scripts will
  have to do the same.
-->

<xsl:variable name="CONFIG" select="document('/home/koen/Documents/GitHub/BrowserC/extern/libtidy/tidy-config.xml')"/>
<xsl:variable name="ENABLE_CONFIG_FILES" select="'ON'"/>
<xsl:variable name="TIDY_CONFIG_FILE" select="'/etc/tidy.conf'"/>
<xsl:variable name="TIDY_USER_CONFIG_FILE" select="'~/.tidyrc'"/>

<!-- Main Template: -->
<xsl:template match="/">
  <xsl:call-template name="header-section" />
  <xsl:call-template name="cmdline-section" />
  <xsl:call-template name="manpage-see-also-section" />
</xsl:template>

<!-- Named Templates: -->

<xsl:template name="header-section">
  <xsl:text/>.\" tidy man page for the HTML Tidy
.TH TIDY 1 "<xsl:value-of select="cmdline/@version" />" "HTML Tidy" "<xsl:value-of select="cmdline/@version" />"
</xsl:template>

<xsl:template name="cmdline-section">
.\" disable hyphenation
.nh
.\" disable justification (adjust text to left margin only)
.ad l
.SH NAME
\fBtidy\fR - check, correct, and pretty-print HTML(5) files
.SH SYNOPSIS
\fBtidy\fR [\fIoptions\fR] [\fIfile\fR ...] [\fIoptions\fR] [\fIfile\fR ...] ...
.SH DESCRIPTION
Tidy reads HTML, XHTML, and XML files and writes cleaned-up markup.  
For HTML variants, it detects, reports, and corrects many common coding errors
and strives to produce visually equivalent markup that is both conformant
to the HTML specifications and that works in most browsers.
.LP
A common use of Tidy is to convert plain HTML to XHTML.  
For generic XML files, Tidy is limited to correcting basic well-formedness
errors and pretty printing.
.LP
If no input file is specified, Tidy reads the standard input.  
If no output file is specified, Tidy writes the tidied markup to the
standard output.  If no error file is specified, Tidy writes messages
to the standard error.
.SH OPTIONS
Tidy supports two different kinds of options.  
Purely \fIcommand-line\fR options, starting with a single dash '\fB-\fR',
can only be used on the command-line, not in configuration files.  
They are listed in the first part of this section.  
\fIConfiguration\fR options, on the other hand, can either be passed
on the command line, starting with two dashes \fB--\fR,
or specified in a configuration file,
using the option name, followed by a colon \fB:\fR, plus the value, without 
the starting dashes. They are listed in the second part of this section,
with a sample config file.
.LP
For \fIcommand-line\fR options that expect a numerical argument,
a default is assumed if no meaningful value can be found.  
On the other hand, \fIconfiguration\fR options cannot be used
without a value; a \fIconfiguration\fR option without a value
is simply discarded and reported as an error.
.LP
Using a \fIcommand-line\fR option is sometimes equivalent to setting
the value of a \fIconfiguration\fR option.  The equivalent option
and value are shown in parentheses in the list below, as they would
appear in a configuration file.  For example,
\fB-quiet, -q\fR (\fIquiet: yes\fR) means that using the
\fIcommand-line\fR option \fB-quiet\fR or \fB-q\fR
is equivalent to setting the \fIconfiguration\fR option
\fIquiet\fR to \fIyes\fR.
.LP
Single-letter \fIcommand-line\fR options without an associated value
can be combined; for example '\fB-i\fR', '\fB-m\fR' and '\fB-u\fR'
may be combined as '\fB-imu\fR'.<xsl:text/>
<xsl:call-template name="show-cmdline-options" />
.SS Configuration Options General
.rs
.LP
\fIConfiguration\fR options can be specified
by preceding each option with \fB--\fR at the command line,
followed by its desired value,
OR by placing the options and values in a configuration file,
and telling tidy to read that file with the \fB-config\fR option:
.LP
.in 1i
\fBtidy --\fR\fIoption1 \fRvalue1 \fB--\fIoption2 \fRvalue2 ...
.br
\fBtidy -config \fIconfig-file \fR ...
.LP
\fIConfiguration\fR options can be conveniently grouped
in a single config file.  
A Tidy configuration file is simply a text file, where each option
is listed on a separate line in the form
.LP
.in 1i
\fIoption1\fR: \fIvalue1\fR
.br
\fIoption2\fR: \fIvalue2\fR
.br
etc.
.LP
The permissible values for a given option depend on the option's Type.  
There are five Types: \fIBoolean\fR, \fIAutoBool\fR, \fIDocType\fR,
\fIEnum\fR, and \fIString\fR.  
\fIBoolean\fR Types allow any of \fByes/no, y/n, true/false, t/f, 1/0\fR.  
\fIAutoBool\fRs allow \fBauto\fR in addition to the values allowed
by \fIBooleans\fR.  
\fIInteger\fR Types take non-negative integers.  
\fIString\fR Types generally have no defaults, and you should provide them in
non-quoted form (unless you wish the output to contain the literal quotes).
.LP
\fIEnum\fR, \fIEncoding\fR, and \fIDocType\fR Types have a fixed repertoire
of items, which are listed in the \fISupported values\fR sections below.
.LP
You only need to provide options and values for those whose defaults you wish
to override, although you may wish to include some already-defaulted options
and values for the sake of documentation and explicitness.
.LP
Here is a sample config file, with at least one example of each of
the five Types:
.LP
    \fI// sample Tidy configuration options
    output-xhtml: yes
    add-xml-decl: no
    doctype: strict
    char-encoding: ascii
    indent: auto
    wrap: 76
    repeated-attributes: keep-last
    error-file: errs.txt
\fR
.LP
Below is a summary and brief description of each of the options.  
They are listed alphabetically within each category.<xsl:text/>
<xsl:call-template name="show-config-options" />
.SH ENVIRONMENT
.TP
.B HTML_TIDY
Name of the default configuration file.  This should be an absolute path,
since you will probably invoke \fBtidy\fR from different directories.  
The value of HTML_TIDY will be parsed after the compiled-in default
(defined with -DTIDY_CONFIG_FILE), but before any of the files specified
using \fB-config\fR.
<xsl:if test="$ENABLE_CONFIG_FILES = 'ON'">
.TP
.B RUNTIME CONFIGURATION FILES
You can also specify runtime configuration files from which \fBtidy\fR will
attempt to load a configuration automatically.
.IP
The system runtime configuration file (<xsl:value-of select="$TIDY_CONFIG_FILE" />),
if it exists will be loaded and applied first, followed by the user runtime
configuration file (<xsl:value-of select="$TIDY_USER_CONFIG_FILE" />).
Subsequent usage of a specific option will override any previous usage.
.IP
Note that if you use the \fBHTML_TIDY\fR environment variable, then the user
runtime configuration file will not be used. This is a feature, not a bug.
</xsl:if>
.SH "EXIT STATUS"
.IP 0
All input files were processed successfully.
.IP 1
There were warnings.
.IP 2
There were errors.
</xsl:template>

<xsl:template name="show-cmdline-options">
.SS File manipulation
  <xsl:call-template name="cmdline-detail">
    <xsl:with-param name="category">file-manip</xsl:with-param>
  </xsl:call-template>
.SS Processing directives
  <xsl:call-template name="cmdline-detail">
    <xsl:with-param name="category">process-directives</xsl:with-param>
  </xsl:call-template>
.SS Character encodings
  <xsl:call-template name="cmdline-detail">
    <xsl:with-param name="category">char-encoding</xsl:with-param>
  </xsl:call-template>
.SS Miscellaneous
  <xsl:call-template name="cmdline-detail">
    <xsl:with-param name="category">misc</xsl:with-param>
  </xsl:call-template>
.SS XML
  <xsl:call-template name="cmdline-detail">
    <xsl:with-param name="category">xml</xsl:with-param>
  </xsl:call-template>
</xsl:template>

<xsl:template name="cmdline-detail">
<!--
  For each option in one of the categories/classes, provide its
    1. names
    2. description
    3. equivalent configuration option
-->
  <xsl:param name="category" />
  <xsl:for-each select='/cmdline/option[@class=$category]'>
<xsl:text>
.TP
</xsl:text>
    <xsl:call-template name="process-names" />
    <xsl:call-template name="process-eqconfig" />
    <xsl:text>
</xsl:text>
    <xsl:apply-templates select="description" />
  </xsl:for-each>
</xsl:template>

<!-- Used only in the cmdline section -->
<xsl:template name="process-names">
  <xsl:for-each select="name">
    <xsl:text />\fB<xsl:value-of select="." />\fR<xsl:text />
    <xsl:if test="position() != last()">
      <xsl:text>, </xsl:text>
    </xsl:if>
  </xsl:for-each>
</xsl:template>

<!-- Used only in the cmdline section -->
<xsl:template name="process-eqconfig">
  <xsl:if test="string-length(eqconfig) &gt; 0">
    <xsl:for-each select="eqconfig">
      <xsl:text> (\fI</xsl:text>
      <xsl:value-of select="." />
      <xsl:text>\fR)</xsl:text>
    </xsl:for-each>
  </xsl:if>
</xsl:template>

<xsl:template name="show-config-options">
.SS Document Display options<xsl:text/>
  <xsl:call-template name="config-detail">
    <xsl:with-param name="category">TidyDisplay</xsl:with-param>
  </xsl:call-template>
.SS Document In and Out options
  <xsl:call-template name="config-detail">
    <xsl:with-param name="category">TidyDocumentIO</xsl:with-param>
  </xsl:call-template>
.SS File Input-Output options
  <xsl:call-template name="config-detail">
    <xsl:with-param name="category">TidyFileIO</xsl:with-param>
  </xsl:call-template>
.SS Diagnostics options
  <xsl:call-template name="config-detail">
    <xsl:with-param name="category">TidyDiagnostics</xsl:with-param>
  </xsl:call-template>
.SS Encoding options
  <xsl:call-template name="config-detail">
    <xsl:with-param name="category">TidyEncoding</xsl:with-param>
  </xsl:call-template>
.SS Cleanup options
  <xsl:call-template name="config-detail">
    <xsl:with-param name="category">TidyMarkupCleanup</xsl:with-param>
  </xsl:call-template>
.SS Entities options
  <xsl:call-template name="config-detail">
    <xsl:with-param name="category">TidyMarkupEntities</xsl:with-param>
  </xsl:call-template>
.SS Repair options
  <xsl:call-template name="config-detail">
    <xsl:with-param name="category">TidyMarkupRepair</xsl:with-param>
  </xsl:call-template>
.SS Transformation options
  <xsl:call-template name="config-detail">
    <xsl:with-param name="category">TidyMarkupXForm</xsl:with-param>
  </xsl:call-template>
.SS Teaching Tidy options
  <xsl:call-template name="config-detail">
    <xsl:with-param name="category">TidyMarkupTeach</xsl:with-param>
  </xsl:call-template>
.SS Pretty Print options
  <xsl:call-template name="config-detail">
    <xsl:with-param name="category">TidyPrettyPrint</xsl:with-param>
  </xsl:call-template>
</xsl:template>


<!--
  Note that any templates called implicitly or explicitly
  from the "config-detail" template below will match on
  the document referred to by the $CONFIG variable, i.e.,
  the file "tidy-config.xml", created by running

      tidy -xml-config > tidy-config.xml

  The $CONFIG variable is set at the top level of this
  stylesheet.
-->

<xsl:template name="config-detail">
<!--
  For each option in one of the 5 categories/classes, provide its
    1. name
    2. Type
    3. default (if any)
    4. example (if any)
    5. description
    6. seealso (if any)
-->
  <xsl:param name="category" />
.rs<xsl:text/>
  <xsl:for-each select='$CONFIG/config/option[@class=$category]'>
    <xsl:sort select="name" order="ascending" />
.TP
<xsl:text>\fB</xsl:text>
  <xsl:text>--</xsl:text><xsl:apply-templates select="name" />
<xsl:text>\fR</xsl:text>
<xsl:text> </xsl:text>
<xsl:text>\fI</xsl:text>
  <xsl:apply-templates select="type" />
<xsl:text>\fR</xsl:text>
<xsl:apply-templates select="default" />
.br
<xsl:apply-templates select="example" />
<xsl:apply-templates select="description" />
<xsl:call-template name="seealso" />
  </xsl:for-each>
</xsl:template>

<!-- Used only in the config options section: -->
<xsl:template name="seealso">
  <xsl:if test="seealso">
    <xsl:text>
</xsl:text>
See also: <xsl:text />
    <xsl:for-each select="seealso">
      <xsl:text />\fB--<xsl:value-of select="." />\fR<xsl:text />
      <xsl:if test="position() != last()">
        <xsl:text>, </xsl:text>
      </xsl:if>
    </xsl:for-each>
  </xsl:if>
</xsl:template>

<!-- Used only in the config options section: -->
<xsl:template match="default[.!='']">
  <xsl:text> (</xsl:text>
  <xsl:text>\fB</xsl:text>
    <xsl:value-of select="." />
  <xsl:text>\fR</xsl:text>
  <xsl:text> if unset)</xsl:text>
</xsl:template>

<!--
  Do not print redundant examples
  (identical for all values of the same Type)
-->
<xsl:template match="
  option[
    type = 'Boolean'
    or type = 'AutoBool'
    or type = 'Integer'
    or type = 'Tag names'
  ]/example" priority="2"
/>

<!-- Used only in the config options section: -->
<xsl:template match="example[.!='']">
  <xsl:text>Supported values: </xsl:text>
  <xsl:text>\fB</xsl:text>
    <xsl:value-of select="." />
  <xsl:text>\fR</xsl:text>
  <xsl:text>&#xA;&#xA;</xsl:text>
</xsl:template>

<!-- Called from the templates below matching `code`, `em`, `strong`: -->
<xsl:template name="escape-backslash">
<!--
  Since backslashes are "special" to the *roff processors used
  to generate man pages, we need to escape backslash characters
  appearing in content with another backslash.
-->
  <xsl:choose>
    <xsl:when test="contains(.,'\')">
      <xsl:value-of select=
        "concat( substring-before(.,'\'), '\\', substring-after(.,'\') )" />
    </xsl:when>
    <xsl:otherwise>
      <xsl:apply-templates />
    </xsl:otherwise>
  </xsl:choose>
</xsl:template>

<!-- Appears at the bottom of the man page: -->
<xsl:template name="manpage-see-also-section">
.SH SEE ALSO
For more information about HTML Tidy:
.RS 4
.LP
https://www.html-tidy.org/
.RE
.LP
For more information on HTML:
.RS 4
.LP
\fBHTML Living Standard\fR (the latest HTML specification)
.br
https://html.spec.whatwg.org/multipage/
.RE
.LP
For bug reports and comments:
.RS 4
.LP
https://github.com/htacg/tidy-html5/issues/
.RE
.LP
Or send questions and comments to \fBpublic-htacg@w3.org\fR.
.LP
Validate your HTML documents using the \fBW3C Nu Markup Validator\fR:
.RS 4
.LP
https://validator.w3.org/nu/
.RE
.SH AUTHOR
\fBTidy\fR was written by \fBDave Raggett\fR &lt;dsr@w3.org&gt;,
and subsequently maintained by a team at http://tidy.sourceforge.net/,
and now maintained by \fBHTACG\fR (https://www.htacg.org).
.LP
The sources for \fBHTML Tidy\fR are available at
https://github.com/htacg/tidy-html5/ under the MIT Licence.
</xsl:template>

<!-- Regular Templates: -->

<xsl:template match="description">
  <xsl:apply-templates />
</xsl:template>

<xsl:template match="a">
  <xsl:apply-templates />
  <xsl:text /> at \fI<xsl:value-of select="@href" />\fR<xsl:text />
</xsl:template>

<xsl:template match="code | em">
  <xsl:text>\fI</xsl:text>
    <xsl:call-template name="escape-backslash" />
  <xsl:text>\fR</xsl:text>
</xsl:template>

<xsl:template match="var">
  <xsl:text>\fB</xsl:text>
    <xsl:call-template name="escape-backslash" />
  <xsl:text>\fR</xsl:text>
</xsl:template>

<xsl:template match="p[1]">
  <xsl:text>
.sp 1
</xsl:text>
  <xsl:text /><xsl:call-template name="escape-backslash" />
</xsl:template>

<xsl:template match="p[position() != 1]">
  <xsl:text>
.sp 1
</xsl:text>
  <xsl:text /><xsl:call-template name="escape-backslash" />
  <xsl:text>
.sp 1
</xsl:text>
</xsl:template>

<xsl:template match="br">
  <xsl:text>
.sp 1
</xsl:text>
</xsl:template>

<xsl:template match="strong">
  <xsl:text />\fB<xsl:call-template name="escape-backslash" />\fR<xsl:text />
</xsl:template>

<!--
  The following templates
    a) normalize whitespace, primarily necessary for `description`
    b) do so without stripping possible whitespace surrounding `code`
    d) strip leading and trailing whitespace in 'description` and `code`
  (courtesy of Ken Holman on the XSL-list):
-->

<xsl:template match="text()[preceding-sibling::node() and
                             following-sibling::node()]">
  <xsl:variable name="ns" select="normalize-space(concat('x',.,'x'))"/>
  <xsl:value-of select="substring( $ns, 2, string-length($ns) - 2 )" />
</xsl:template>

<xsl:template match="text()[preceding-sibling::node() and
                             not( following-sibling::node() )]">
  <xsl:variable name="ns" select="normalize-space(concat('x',.))"/>
  <xsl:value-of select="substring( $ns, 2, string-length($ns) - 1 )" />
</xsl:template>

<xsl:template match="text()[not( preceding-sibling::node() ) and
                             following-sibling::node()]">
  <xsl:variable name="ns" select="normalize-space(concat(.,'x'))"/>
  <xsl:value-of select="substring( $ns, 1, string-length($ns) - 1 )" />
</xsl:template>

<xsl:template match="text()[not( preceding-sibling::node() ) and
                             not( following-sibling::node() )]">
  <xsl:value-of select="normalize-space(.)"/>
</xsl:template>

</xsl:stylesheet>
