/* interact.h was originally generated by the autoSql program, which also 
 * generated interact.c and interact.sql.  This header links the database and
 * the RAM representation of objects. */

#ifndef INTERACT_H
#define INTERACT_H

#include "jksql.h"
#define INTERACT_NUM_COLS 16

extern char *interactCommaSepFieldNames;

struct interact
/* Interaction between two regions */
    {
    struct interact *next;  /* Next in singly linked list. */
    char *chrom;	/* Chromosome (or contig, scaffold, etc.). For interchromosomal, use 2 records */
    unsigned chromStart;	/* Start position in chromosome of lower region. For interchromsomal, chromStart of this region */
    unsigned chromEnd;	/* End position in chromosome of upper region. For interchromosomal, set to chromEnd of this region */
    char *name;	/* Name of item, for display.  Usually 'name1/name2' or empty */
    unsigned score;	/* Score from 0-1000 */
    double value;	/* Strength of interaction or other data value. Typically basis for score */
    char *exp;	/* Experiment name (metadata for filtering) or empty. */
    unsigned color;	/* Item color, as itemRgb in bed9. Typically based on strength or filter */
    char *sourceChrom;	/* Chromosome of source region (directional) or lower region. For interchromosomal, set to chrom of this region*/
    unsigned sourceStart;	/* Start position in chromosome of source/lower/this region */
    unsigned sourceEnd;	/* End position in chromosome of source/lower/this region */
    char *sourceName;	/* Identifier of source/lower/this region. Can be used as link to related table */
    char *targetChrom;	/* Chromosome of target region (directional) or upper region. for interchromsomal, set to chrom of other region */
    unsigned targetStart;	/* Start position in chromosome of target/upper/other region */
    unsigned targetEnd;	/* End position in chromosome of target/upper/other region */
    char *targetName;	/* Identifier of target/upper region. Can be used as link to related table */
    };

void interactStaticLoad(char **row, struct interact *ret);
/* Load a row from interact table into ret.  The contents of ret will
 * be replaced at the next call to this function. */

struct interact *interactLoadByQuery(struct sqlConnection *conn, char *query);
/* Load all interact from table that satisfy the query given.  
 * Where query is of the form 'select * from example where something=something'
 * or 'select example.* from example, anotherTable where example.something = 
 * anotherTable.something'.
 * Dispose of this with interactFreeList(). */

void interactSaveToDb(struct sqlConnection *conn, struct interact *el, char *tableName, int updateSize);
/* Save interact as a row to the table specified by tableName. 
 * As blob fields may be arbitrary size updateSize specifies the approx size
 * of a string that would contain the entire query. Arrays of native types are
 * converted to comma separated strings and loaded as such, User defined types are
 * inserted as NULL. This function automatically escapes quoted strings for mysql. */

struct interact *interactLoad(char **row);
/* Load a interact from row fetched with select * from interact
 * from database.  Dispose of this with interactFree(). */

struct interact *interactLoadAll(char *fileName);
/* Load all interact from whitespace-separated file.
 * Dispose of this with interactFreeList(). */

struct interact *interactLoadAllByChar(char *fileName, char chopper);
/* Load all interact from chopper separated file.
 * Dispose of this with interactFreeList(). */

#define interactLoadAllByTab(a) interactLoadAllByChar(a, '\t');
/* Load all interact from tab separated file.
 * Dispose of this with interactFreeList(). */

struct interact *interactCommaIn(char **pS, struct interact *ret);
/* Create a interact out of a comma separated string. 
 * This will fill in ret if non-null, otherwise will
 * return a new interact */

void interactFree(struct interact **pEl);
/* Free a single dynamically allocated interact such as created
 * with interactLoad(). */

void interactFreeList(struct interact **pList);
/* Free a list of dynamically allocated interact's */

void interactOutput(struct interact *el, FILE *f, char sep, char lastSep);
/* Print out interact.  Separate fields with sep. Follow last field with lastSep. */

#define interactTabOut(el,f) interactOutput(el,f,'\t','\n');
/* Print out interact as a line in a tab-separated file. */

#define interactCommaOut(el,f) interactOutput(el,f,',',',');
/* Print out interact as a comma separated list including final comma. */

/* -------------------------------- End autoSql Generated Code -------------------------------- */

struct asObject *interactAsObj();
/* Return asObject describing fields of barChart database table (includes bin) */

char *interactOtherChrom(struct interact *inter);
/* Get other chromosome from an interaaction. Return NULL if same chromosome */

#endif /* INTERACT_H */
