
**test_makefiles** contains several Makefiles :

## Parsing TESTS

- **MakefileParsing2** generate **miniRT_parsing_2** . This file prints a line with clean spaces and determine the element and if the *type element info*  has valid or no valid format 
- **MakefileParsing5** generate **miniRT_parsing_5** . Prints info scene converted correct numeric format or error if 'rt' file has any misconfiguration.

## Previous TESTS
- **MakefileIsCoor** use **test_iscoordenate.c** to check if several strings are valid *coordinate* or not.
- **MakefileIsFOV** use **test_isfov.c** to check if several strings are valid *FOV* or not.
- **MakefileIsOrientNormal** use **test_isorientnormal.c** to check if several strings are valid *Normal Vector* or not.
- **MakefileIsRGB** use **test_isrgbstr.c** to check if several strings are valid *RGB vector* or not.
- **MakefileStrToFloatCeroOne** use **teststrtofloatceroone.c** to check if several strings are valid *float in range [0.0,1.0]* or not. 
- **MakefileStrToFloatPositive** use **teststrtofloatpositve.c** to check if several strings are valid *float >= 0.0* or not. 
- **MakefileStrToFloatSgn** use **teststrtofloatsgn.c** to check if several strings are valid *float* or not. 
- **MakefileStrToFloatSgnOne** use **teststrtofloatsgnione.c** to check if several strings are valid *float range [-1.0,1.0]* or not. 
- **MakefileTestCleanSpaces_1** use **test_cleanspaces.c** to convert several strings with one or more spaces inside to a new string witih only one space between chars.
- **MakefileTestLimitsFloat** compile **test_floatlimits.c** to see float limits on computer.
- **MakefileTestStringToRgbFov** use **test_stringtorgbfov.c** to check if several strings are valid *RGB value as int in rage [0,255] or FOB as int in range [0,180]*
- **MakefileTestList_1** , **MakefileTestList_2** use **testList1.c** , **testList2.c** . For understand use of *t_list* from *libft*
- **MakefileTestStructScene** use **test_struct_scene.c** to test the use of *t_scene* in **miniRT**.
