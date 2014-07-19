x-thesaurus
===========

A terminal client to lookup synonyms of an english word. x-thesaurus uses the [Big Huge Thesaurus](https://words.bighugelabs.com/api.php) api to serve the synonyms to it's users. please get your own api key from [Big Huge Thesaurus](https://words.bighugelabs.com/api.php) and replace it with YOURAPIKEY in the [x-thesaurus.h](src/x-thesaurus.h)

Usage
-----
as of now it is only supported in *nix based systems.

`x-thesaurus word`

will do the job

######examples
`x-thesaurus word`
`x-thesaurus computer\ science`
`x-thesaurus sceptical pint interested open boss`

### Goodies for programmers
There is a C++ wrapper to [http-get.c](https://github.com/stephenmathieson/http-get.c) in lib.

##TO-DO
create maximum number of results argument
show only nouns argument
show only verbs argument
show only synonyms argument
show only antonyms argument
*declarations of list map vector constants are pretty ugly in [x-thesaurus.h](src/x-thesaurus.h)