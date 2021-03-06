# hapmapSnpsCombined.sql was originally generated by the autoSql program, which also 
# generated hapmapSnpsCombined.c and hapmapSnpsCombined.h.  This creates the database representation of
# an object which can be loaded and saved from RAM in a fairly 
# automatic way.

#HapMap genotype summaries for all populations
CREATE TABLE hapmapSnpsCombined (
    bin int unsigned not null,  	# For browser speed up
    chrom varchar(255) not null,	# Chromosome
    chromStart int unsigned not null,	# Start position in chrom (0 based)
    chromEnd int unsigned not null,	# End position in chrom (1 based)
    name varchar(255) not null,		# Reference SNP identifier from dbSnp
    score int unsigned not null,	# Not used
    strand enum ('+', '-', '?') default '?' not null,	# Which genomic strand contains the observed alleles
    observed varchar(255) not null,	# Observed string from genotype file
    allele1 enum('A', 'C', 'G', 'T')  not null,	# This allele has been observed
    homoCount1CEU int unsigned not null,	# Count of CEU individuals who are homozygous for allele1
    homoCount1CHB int unsigned not null,	# Count of CHB individuals who are homozygous for allele1
    homoCount1JPT int unsigned not null,	# Count of JPT individuals who are homozygous for allele1
    homoCount1YRI int unsigned not null,	# Count of YRI individuals who are homozygous for allele1
    allele2 enum ('C', 'G', 'T', 'none') not null,	# This allele may not have been observed
    homoCount2CEU int unsigned not null,	# Count of CEU individuals who are homozygous for allele2
    homoCount2CHB int unsigned not null,	# Count of CHB individuals who are homozygous for allele2
    homoCount2JPT int unsigned not null,	# Count of JPT individuals who are homozygous for allele2
    homoCount2YRI int unsigned not null,	# Count of YRI individuals who are homozygous for allele2
    heteroCountCEU int unsigned not null,	# Count of CEU individuals who are heterozygous
    heteroCountCHB int unsigned not null,	# Count of CHB individuals who are heterozygous
    heteroCountJPT int unsigned not null,	# Count of JPT individuals who are heterozygous
    heteroCountYRI int unsigned not null,	# Count of YRI individuals who are heterozygous
              #Indices
    INDEX name (name),
    INDEX chrom (chrom, bin)
);
