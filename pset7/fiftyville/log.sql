-- Keep a log of any SQL queries you execute as you solve the mystery.
 Theft of the CS50 duck took place at 10:15am at the Chamberlin Street courthouse. Interviews were conducted today with
 three witnesses who were present at the time — each of their interview transcripts mentions the courthouse.

| 161 | Ruth    | 2020 | 7     | 28  | Sometime within ten minutes of the theft, I saw the thief get
into a car in the courthouse parking lot and drive away. If you have security
footage from the courthouse parking lot, you might want to look for
cars that left the parking lot in that time frame.

create table sus_call as
select * from phone_calls a
inner join people b on b.phone_number = a.caller
inner join people c on c.phone_number = a.receiver
and a.day = 28 and a.month =7 and a.year = 2020 and a.duration < 60;

create table sus_cars as
select * from
courthouse_security_logs a
inner join people b on b.license_plate = a.license_plate
where a.day=28 and a.month=7
and a.year = 2020
and activity = 'exit' and hour=10 and minute >= 15 and minute<=25;
                                       |
| 162 | Eugene  | 2020 | 7     | 28  | I don't know the thief's name, but it was someone I recognized.
Earlier this morning, before I arrived at the courthouse, I was walking by the ATM on Fifer Street and
 saw the thief there withdrawing some money.

create table sus_atm as
select
*
from
atm_transactions a
inner join bank_accounts b on a.account_number = b.account_number
inner join people c on c.id = b.person_id
where a.year = 2020 and day = 28 and month = 7
and atm_location = 'Fifer Street' and transaction_type = 'withdraw'

select
select
c."id:1" ,
c.name ,
c.phone_number ,
c.passport_number ,
c.license_plate ,
c."id:2",
c."name:1",
c."phone_number:1",
c."passport_number:1",
c."license_plate:1"
from
sus_cars a
inner join sus_atm b on a."id:1" = b."id:1"
inner join sus_call c on c."id:1" = b."id:1";

select
a.*
from
flights a
inner join airports b on b.id = a.origin_airport_id
inner join passengers c on c.flight_id = a.id
where a.year = 2020 and a.month = 7 and a.day = 29
and b.city = 'Fiftyville' and c.passport_number in ('3592750733','5773159633');
                                                                                       |
| 163 | Raymond | 2020 | 7     | 28  | As the thief was leaving the courthouse, they called someone who
 talked to them for less than a minute. In the call, I heard the thief say that they were planning
 to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other
 end of the phone to purchase the flight ticket. |


select description from crime_scene_reports
where
day = 28 and month = 7
and street = 'Chamberlin Street';

select * from
interviews a
where a.day=28 and a.month=7
and a.year = 2020 and transcript like '%courthouse%';

select b.id from
courthouse_security_logs a
inner join people b on b.license_plate = a.license_plate
where a.day=28 and a.month=7
and a.year = 2020 and hour < 10 and minute <15 and activity = 'exit';

select
a.*
from
atm_transactions a
inner join bank_accounts b on a.account_number = b.account_number
inner join people c on c.id = b.person_id
where a.year = 2020 and day = 28 and month = 7
and atm_location = 'Fifer Street';

select a.*,c.* from phone_calls a
inner join people b on b.phone_number = a.caller
inner join people c on c.phone_number = a.receiver and c.passport_number is not null
where caller in (
select phone_number from
courthouse_security_logs a
inner join people b on b.license_plate = a.license_plate
where a.day=28 and a.month=7
and a.year = 2020
and activity = 'exit'
and b.id in (
select
c.id
from
atm_transactions a
inner join bank_accounts b on a.account_number = b.account_number
inner join people c on c.id = b.person_id
where a.year = 2020 and day = 28 and month = 7
and atm_location = 'Fifer Street' and transaction_type = 'withdraw'))
and a.day = 28 and a.month =7 and a.year = 2020 and a.duration < 60;

select
a.*,c.passport_number
from
flights a
inner join airports b on b.id = a.origin_airport_id
inner join passengers c on c.flight_id = a.id
where a.year = 2020 and a.month = 7 and a.day = 29
and b.city = 'Fiftyville'
and c.passport_number in (
select passport_number from phone_calls a
inner join people b on b.phone_number = a.receiver
where caller in (
select phone_number from
courthouse_security_logs a
inner join people b on b.license_plate = a.license_plate
where a.day=28 and a.month=7
and a.year = 2020
and activity = 'exit'
and b.id in (
select
c.id
from
atm_transactions a
inner join bank_accounts b on a.account_number = b.account_number
inner join people c on c.id = b.person_id
where a.year = 2020 and day = 28 and month = 7
and atm_location = 'Fifer Street'))
and a.day = 28 and a.month =7 and a.year = 2020 and a.duration < 60);