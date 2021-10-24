-- Introduction
/* 
The CS50 Duck has been stolen! The town of Fiftyville has called upon you to solve the mystery of the stolen duck. 
Authorities believe that the thief stole the duck and then, shortly afterwards, took a flight out of town with the help of an accomplice. 

Your goal is to identify:

Who the thief is,
What city the thief escaped to, and
Who the thief’s accomplice is who helped them escape

All you know is that the theft took place on July 28, 2020 and that it took place on Chamberlin Street.

How will you go about solving this mystery? 
The Fiftyville authorities have taken some of the town’s records from around the time of the theft and prepared a SQLite database for you, 
fiftyville.db, which contains tables of data from around the town. 
You can query that table using SQL SELECT queries to access the data of interest to you. 
Using just the information in the database, your task is to solve the mystery.
*/



-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Check the crime scence report at July 28 at Chamberlin Street.
SELECT description FROM crime_scene_reports
WHERE year = 2020 AND month = 07 AND day = 28 AND street = 'Chamberlin Street';
/*
Return: 
Theft of the CS50 duck took place at 10:15am at the Chamberlin Street courthouse. 
Interviews were conducted today with three witnesses who were present at the time 
each of their interview transcripts mentions the courthouse.

-- Summary
1. took place at 10:15am 
2. place:  Chamberlin Street courthouse
3. witenesses: three witnesses was conducted the interveiws at that time.
4. transcrips: each of their mentioned courthouse.
*/

-- TODO: find the transcripts that three witnesses told. (you can specify to use date and the statement that they mentioned.)
SELECT name, transcript FROM interviews
WHERE year = 2020 AND month = 7 AND day = 28
AND transcript LIKE '%courthouse%';

/*
Return:
Ruth|Sometime within ten minutes of the theft, I saw the thief get into a car in the courthouse parking lot and drive away. 
If you have security footage from the courthouse parking lot, you might want to look for cars that left the parking lot in that time frame.

Eugene|I don't know the thief's name, but it was someone I recognized. 
Earlier this morning, before I arrived at the courthouse, I was walking by the ATM on Fifer Street and saw the thief there withdrawing some money.

Raymond|As the thief was leaving the courthouse, they called someone who talked to them for less than a minute. 
In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. 
The thief then asked the person on the other end of the phone to purchase the flight ticket.

-- Summary

1. thief have car, and it was in the courthouse parking lot. and drived away with taht car
2. Early morning ATM on Fifer Street the thief wirhdraing some money.
3. theif called someone less a minute.
4. earliest flight out of Fiftyville tomorrow(20200729) * earliest means the first flight.
5. accomplice will purchase the flight ticket.
*/

-- TODO
-- check security footage from the courthouse, timestamp will be the time when left the parking lot.
-- time within ten minutes from 10:15, so 10:15 ~ 25. 
-- this time we can find the name by using JOIN the other thable called people since the Table includes license_plate
SELECT name FROM people
JOIN courthouse_security_logs 
ON people.license_plate = courthouse_security_logs.license_plate 
WHERE year = 2020 AND month = 7 AND day = 28 AND hour = 10
AND minute BETWEEN 15 AND 25
AND activity = 'exit';

/*
Return:

Patrick
Ernest
Amber
Danielle
Roger
Elizabeth
Russell
Evelyn

--Summary
got the name of the suspectors !!

*/

-- TODO
-- check atm transaction on Fifer street
-- tranaction type: withdraw
-- time before 10:15
-- filter those suspectors are includes or not.

SELECT name FROM atm_transactions
JOIN bank_accounts                                                 
ON atm_transactions.account_number = bank_accounts.account_number
JOIN people                                                       
ON bank_accounts.person_id = people.id
WHERE year = 2020 AND month = 7 AND day = 28
AND transaction_type = 'withdraw'                                  
AND atm_location = 'Fifer Street'                                  
AND name IN ('Patrick', 'Ernest', 'Amber', 'Danielle', 'Roger', 'Elizabeth', 'Russell', 'Evelyn');


/*
Return:

Ernest
Russell
Elizabeth
Danielle

--Summary
we reduced the number of suspectors by half !!
*/

-- TODO
-- check phone call receiver and caller at the date
-- duration less than a minute.
-- filter by the name of suspectors.

SELECT name FROM phone_calls
JOIN people
ON  phone_calls.caller = people.phone_number
WHERE year = 2020 AND month = 7 AND day = 28
AND duration < 60
AND name in ('Ernest', 'Russell', 'Elizabeth', 'Danielle');

/*
Return:

Ernest
Russell

--Summary
almost there dude!
*/



/**************************** 
In case you do not use JOIN, will happen this for you lol, 
actually I thought eye-balling is better than sql at this moment lol.
however, I jsut was so dumb...


SELECT * FROM people JOIN bank_accounts
ON people.id = bank_accounts.person_id
WHERE people.license_plate IN ('5P2BI95', '94KL13X', '6P58WS2', '4328GD8', 'G412CB7', 'L93JTIZ', '322W7JE', '0NTHK55')                                       
AND people.phone_number IN ( '(130) 555-0289', '(499) 555-9472', '(367) 555-5533', '(499) 555-9472', '(286) 555-6063', '(770) 555-1861', '(031) 555-6622', '(826) 555-1652', '(338) 555-6650')
AND bank_accounts.account_number IN ( 28500762, 28296815, 76054385, 49610011, 16153065, 25506511, 81061156, 26013199);

Return:
686048|Ernest|(367) 555-5533|5773159633|94KL13X|49610011|686048|2010
514354|Russell|(770) 555-1861|3592750733|322W7JE|26013199|514354|2012

********************************/


-- TODO 
-- who was in earliest flight out of Fiftyville tomorrow(20200729) * earliest means the first flight.

SELECT name FROM people 
JOIN passengers 
ON people.passport_number = passengers.passport_number
JOIN flights
ON passengers.flight_id = flights.id
JOIN airports
ON flights.origin_airport_id = airports.id
WHERE year = 2020 AND month = 7 AND day = 29
AND name IN ('Ernest', 'Russell')
ORDER BY hour, minute ASC LIMIT 1;


/*
Return:

Ernest

Summary: 
gotcha!

Theif information
686048|Ernest|(367) 555-5533|5773159633|94KL13X

*/

-- TODO: Where the theif escape to ? 

SELECT city FROM airports 
JOIN flights 
ON airports.id = flights.destination_airport_id
JOIN passengers
ON flights.id = passengers.flight_id
WHERE passport_number = 5773159633;

/*
Return:
London
*/

-- TODO: Who is accomplice?
-- we can find the accomplice from the phonce call database, accomplice will be receiver of the thief.


SELECT name FROM people
JOIN phone_calls
ON people.phone_number = phone_calls.receiver
WHERE year = 2020 AND month = 7 AND day = 28
AND duration < 60
AND phone_calls.caller = '(367) 555-5533';

/*
Return:

Berthold
*/










