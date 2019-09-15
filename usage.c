/* *************** */
/* Usage functions */
/* *************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "usage.h"
#include "ctxopt.h"

/* ====================== */
/* Usage display and exit */
/* ====================== */
void
main_usage(void)
{
  ctxopt_disp_usage(continue_after);

  printf("\n----------\n");
  printf("\nThis is a filter that gets words from stdin or from a file and ");
  printf("outputs\n");
  printf("the selected words (or nothing) on stdout in a nice selection ");
  printf("window\n\n");
  printf("The selection window appears on /dev/tty ");
  printf("just below the current line\n");
  printf("(no clear screen!).\n\n");
  printf("The following options are available:\n\n");
  printf("-h|-help\n");
  printf("  displays this help.\n");
  printf("-f|-cfg|-config_file\n");
  printf("  selects an alternative configuration file.\n");
  printf("-n|-lines|-height\n");
  printf("  sets the number of lines in the selection window.\n");
  printf("-t|-tab_mode|-tabulate_mode\n");
  printf("  tabulates the items. The number of columns can be limited with\n");
  printf("  an optional number.\n");
  printf("-k|-ks|-keep_spaces\n");
  printf("  does not trim spaces surrounding the output string if any.\n");
  printf("-v|-vb|-visual_bell\n");
  printf("  makes the bell visual (fuzzy search with error).\n");
  printf("-s|-sp|-start|-start_pattern\n");
  printf("  sets the initial cursor position (read the manual for "
         "more details).\n");
  printf("-m|-msg|-message|-title\n");
  printf("  displays a one-line message above the window.\n");
  printf("-w|-wt|-wide_tab_mode\n");
  printf("  uses all the terminal width for the columns if their numbers "
         "is given.\n");
  printf("-d|-delete_window|-clean_window\n");
  printf("  deletes the selection window on exit.\n");
  printf("-M|-middle|-center\n");
  printf("  centers the display if possible.\n");
  printf("-c|-col|-col_mode|-column\n");
  printf("  is like|-t without argument but respects end of lines.\n");
  printf("-l|-line|-line_mode\n");
  printf("  is like|-c without column alignments.\n");
  printf("-r|-auto_validate\n");
  printf("  enables ENTER to validate the selection even in search mode.\n");
  printf("-b|-blank\n");
  printf("  displays non printable characters as space.\n");
  printf("-a|-attributes\n");
  printf("  sets the attributes for the various displayed elements.\n");
  printf("-i|-include\n");
  printf("  sets the regex input filter to match the selectable words.\n");
  printf("-e|-exclude\n");
  printf("  sets the regex input filter to match the non-selectable words.\n");
  printf("-C|-cs|-col_select\n");
  printf("  sets columns restrictions for selections.\n");
  printf("-R|-rs|-row_select\n");
  printf("  sets rows restrictions for selections.\n");
  printf("-S|-subst\n");
  printf("  sets the post-processing action to apply to all words.\n");
  printf("-I|-si|-subst_included\n");
  printf("  sets the post-processing action to apply to selectable "
         "words only.\n");
  printf("-E|-se|-subst_excluded\n");
  printf("  sets the post-processing action to apply to non-selectable "
         "words only.\n");
  printf("-A|-fc|-first_column\n");
  printf("  forces a class of words to be the first of the line they "
         "appear in.\n");
  printf("-Z|-lc|-last_column\n");
  printf("  forces a class of words to be the latest of the line they "
         "appear in.\n");
  printf("-N|-number/-U|-unnumber\n");
  printf("  numbers/un-numbers and provides a direct access to words "
         "matching\n");
  printf("  (or not) a specific regex.\n");
  printf("-F|-en|-embedded_number\n");
  printf("  numbers and provides a direct access to words by extracting the "
         "number\n");
  printf("  from the words.\n");
  printf("-1|-l1|-level1,-2|-l2|-level2,...,-5|-l5|-level5\n");
  printf("  gives specific colors to up to 5 classes of "
         "selectable words.\n");
  printf("-g|-gutter\n");
  printf("  separates columns with a character in column or tabulate "
         "mode.\n");
  printf("-q|-no_bar|-no-scroll_bar\n");
  printf("  prevents the display of the scroll bar.\n");
  printf("-W|-ws|-wd|-word_delimiters|-word_separators\n");
  printf("  sets the input words separators.\n");
  printf("-L|-ls|-ld|-line-delimiters|-line_separators\n");
  printf("  sets the input lines separators.\n");
  printf("-T|-tm|-tag_mode/-P|-pm|-pin_mode\n");
  printf("  enables the tagging (multi-selections) mode. ");
  printf("An optional parameter\n");
  printf("  sets the separator string between the selected words ");
  printf("on the output.\n");
  printf("  A single space is the default separator.\n");
  printf("-p|-at|-auto_tag\n");
  printf("  activates the auto-tagging when using -T or -P.\n");
  printf("-V|-version\n");
  printf("  displays the current version and quits.\n");
  printf("-x|-timeout/-X|-hidden_timeout\n");
  printf("  sets a timeout and specifies what to do when it expires.\n");
  printf("-/|-search_method\n");
  printf("  changes the affectation of the / key (default fuzzy search).\n");
  printf("\nNavigation keys are:\n");
  printf("  - Left/Down/Up/Right arrows or h/j/k/l, H/J/K/L.\n");
  printf("  - Home/End, SHIFT|CTRL+Home/End CTRK+J/CTRL+K.\n");
  printf("  - Numbers if some words are numbered (-N/-U/-F).\n");
  printf("  - SPACE to search for the next match of a previously\n");
  printf("          entered search prefix if any, see below.\n\n");
  printf("Other useful keys are:\n");
  printf("  - Help key (temporary display of a short help line): "
         "?\n");
  printf("  - Exit key without output (do nothing)             : "
         "q\n");
  printf("  - Tagging keys: Select/Deselect/Toggle             : "
         "INS/DEL/t\n");
  printf("  - Selection key                                    : "
         "ENTER\n");
  printf("  - Cancel key                                       : "
         "ESC\n");
  printf("  - Search key                                       : "
         "/ or CTRL-F\n\n");
  printf("The search key activates a timed search mode in which\n");
  printf("you can enter the first letters of the searched word.\n");
  printf("When entering this mode you have 7s to start typing\n");
  printf("and each entered letter gives you 5 more seconds before\n");
  printf("the timeout. After that the search mode is ended.\n\n");
  printf("Notes:\n");
  printf("- the timer can be cancelled by pressing ESC.\n");
  printf("- a bad search letter can be removed with ");
  printf("CTRL-H or Backspace.\n\n");
  printf("(C) Pierre Gentile.\n\n");

  exit(EXIT_FAILURE);
}

void
da_ctx_usage(void)
{
  ctxopt_disp_usage(continue_after);

  printf("\nDirect access specific help.\n\n");
  printf("The following parameters are available in this context:\n\n");
  printf("-h|-help\n");
  printf("  displays this help.\n");
  printf("-D|-data|-options:\n");
  printf("  sets sub-options to modify the behaviour of -N|-number,\n");
  printf("  -U|-unnumber and -F|-en|-embedded_number.\n");

  exit(EXIT_FAILURE);
}
