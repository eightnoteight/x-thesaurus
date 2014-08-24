x-thesaurus
===========

A terminal client to lookup synonyms of an english word. x-thesaurus uses the [Big Huge Thesaurus](https://words.bighugelabs.com/api.php) api to serve the synonyms to it's users. please get your own api key from [Big Huge Thesaurus](https://words.bighugelabs.com/api.php) and replace it with YOURAPIKEY in the [x-thesaurus.h](src/x-thesaurus.h)

Platform
--------
    as of now it is only supported in *nix based systems

Usage
-----

`x-thesaurus [word]`

will do the job

######examples
`x-thesaurus word`
`x-thesaurus computer\ science`
`x-thesaurus sceptical pint interested open boss`

### Goodies for programmers
There is a C++ wrapper to [http-get.c](https://github.com/stephenmathieson/http-get.c) in lib.

##TO-DO
1. create maximum number of results argument
2. create definitions for tmp directory (to play in windows)
3. show only nouns argument
4. show only verbs argument
5. show only synonyms argument
6. show only antonyms argument
7. declarations of list map vector constants are ugly in [x-thesaurus.h](src/x-thesaurus.h)
8. filter any puctuation from the words
