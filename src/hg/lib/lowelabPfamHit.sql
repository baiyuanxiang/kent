# lowelabPfamHit.sql was originally generated by the autoSql program, which also 
# generated lowelabPfamHit.c and lowelabPfamHit.h.  This creates the database representation of
# an object which can be loaded and saved from RAM in a fairly 
# automatic way.

#Pfam domain hits mapped to the genome
CREATE TABLE lowelabPfamHits (
    bin int unsigned not null, 
    chrom varchar(255) not null,	# chromosome
    chromStart int unsigned not null,	# Start position in chromosome
    chromEnd int unsigned not null,	# End position in chromosome
    name varchar(255) not null,	# hit name
    score int unsigned not null,	# Score from 900-1000.  1000 is best
    strand char(1) not null,	# Value should be + or -
    pfamAC varchar(255) not null,	# Pfam accession number
    pfamID varchar(255) not null,	# Pfam ID
    swissAC varchar(255) not null,	# SWISS-PROT accession number
    protCoord varchar(255) not null,	# Coordiates of Pfam domain hit within organism protein
    ident int unsigned not null,	# Percent identity of Pfam-A seq with this hit (should be >90%)
    percLen int unsigned not null,	# Percent length of Pfam domain relative to protein length)
              #Indices
    PRIMARY KEY(name,chrom,chromStart)
);
