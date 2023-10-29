select distinct * from
(select c.car_id, c.car_type, floor(daily_fee * 30 * ((100 - discount_rate) / 100)) as fee from CAR_RENTAL_COMPANY_CAR as c
 join CAR_RENTAL_COMPANY_RENTAL_HISTORY as h on c.car_id = h.car_id
join (select * from CAR_RENTAL_COMPANY_DISCOUNT_PLAN where (car_type = '세단' or car_type = 'SUV') and duration_type like '30%') as p on c.car_type = p.car_type
 
where ((c.car_type = '세단' or c.car_type = 'SUV') and c.car_id not in (select car_id from CAR_RENTAL_COMPANY_RENTAL_HISTORY as h where (h.start_date <= '2022-11-01%' and h.end_date >= '2022-11-01%')
or (h.start_date >= '2022-11-01%' and h.end_date >= '2022-11-01%')))) as t
where fee between 500000 and 2000000
order by fee desc, car_type, car_id desc

# SELECT C.CAR_ID, C.CAR_TYPE, FLOOR(DAILY_FEE * (1 - (DISCOUNT_RATE) / 100) * 30) AS FEE
# FROM CAR_RENTAL_COMPANY_CAR C 
#      JOIN (SELECT CAR_TYPE, DISCOUNT_RATE 
#                 FROM CAR_RENTAL_COMPANY_DISCOUNT_PLAN
#                 WHERE DURATION_TYPE = "30일 이상") P
#         ON C.CAR_TYPE = P.CAR_TYPE
# WHERE C.CAR_TYPE IN ("세단", "SUV")
#         AND C.CAR_ID NOT IN (SELECT CAR_ID
#                              FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY 
#                              WHERE ((START_DATE BETWEEN "2022-11-01" AND "2022-11-30") OR (END_DATE  BETWEEN "2022-11-01" AND "2022-11-30")) OR (START_DATE < "2022-11-01" AND END_DATE > "2022-11-30"))
#         AND FLOOR(DAILY_FEE * (1 - (DISCOUNT_RATE) / 100) * 30) BETWEEN 500000 AND 1999999
# ORDER BY FEE DESC, C.CAR_TYPE ASC, C.CAR_ID DESC;

# select car_id from CAR_RENTAL_COMPANY_RENTAL_HISTORY where 
# (h.start_date <= '2022-11-01%' and h.end_date >= '2022-11-01%')
# or (h.start_date >= '2022-11-01%' and h.end_date >= '2022-11-01%')