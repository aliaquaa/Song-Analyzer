# Tests for `SENG 265`, Assignment #1

* Pre-requisites
    * Configuration of required libraries (executed only once after connecting to Ref. Plat.): `setSENG265`
    * Compilation: `gcc song_analyzer.c -std=c99 -o song_analyzer` 
    * Enable the execution of tester: `chmod u+x tester`

* Test 1
    * Input: `before_2020s.csv`
    * Expected output: `test01.csv`
    * Test: `./tester 1`
    * Command automated by tester: `./song_analyzer --question=1 --data=before_2020s.csv`
    
* Test 2
    * Input: `during_2020s.csv`
    * Expected output: `test02.csv`
    * Test: `./tester 2`
    * Command automated by tester: `./song_analyzer --question=2 --data=during_2020s.csv`
    
* Test 3
    * Input: `before_2020s.csv`
    * Expected output: `test03.csv`
    * Test: `./tester 3`
    * Command automated by tester: `./song_analyzer --question=3 --data=before_2020s.csv`

* Test 4
    * Input: `during_2020s.csv`
    * Expected output: `test04.csv`
    *  Test: `./tester 4`
    * Command automated by tester: `./song_analyzer --question=4 --data=during_2020s.csv`
    

* Test 5
    * Input: `during_2020s.csv`
    * Expected output: `test05.csv`
    * Test: `./tester 5`
    * Command automated by tester: `./song_analyzer --question=5 --data=during_2020s.csv`
    