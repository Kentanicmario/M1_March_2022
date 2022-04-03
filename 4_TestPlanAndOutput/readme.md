# TEST PLAN
## HIGH LEVEL TEST PLAN

| TEST ID |         DESCRIPTION               |                   EXP I/P                | EXP O/P   |  ACTUAL OUT | TYPE OF TEST |
| :---    |     :---:                         |                                     ---: |  ---:     |         --: |          --: |    
| H_01    | Tested login credentials          | username, password                       | Success   | Success     | Technical    |   
| H_02    | Tested arrival of vehicle         | Choice number, 2-wheeler or 4-wheeler no | Success   | Success     | Technical    |  
| H_03    | Tested departure of vehicle       | Choice number, 2-wheeler or 4-wheeler no | Success   | Success     | Technical    |    
| H_04    | Tested display of vehicle parked  | Choice number                            | Success   | Success     | Technical    |    
| H_05    | Tested total number of vehicles   | Choice number                            | Success   | Success     | Technical    |    


## LOW LEVEL TEST PLAN

| TEST ID |   HLT       |                   DESCRIPTION                        |                EXP I/P                   |  EXP O/P    | ACTUAL OUT | TYPE OF TEST |
|    :--- |     :---:   |                                                 ---: |                                 ---:     |         --: |        --: |          --: |  
| L_01    |  H_01       | Tested on function which accept two choices as input | username, password                       |    Success  | Success    |   Technical  |
| L_02    |  H_02, H_03 | Tested on function which accept two choices as input | choice number, 2-wheeler or 4-wheeler no |    Success  | Success    |   Technical  |
| L_03    |  H_04, H_05 | Tested on function which accept one choice as input  | Choice number                            |    Success  | Success    |   Technical  | 
 


