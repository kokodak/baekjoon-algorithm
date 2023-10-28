-- 코드를 입력하세요
SELECT mp.MEMBER_NAME, rr.REVIEW_TEXT, substring(rr.REVIEW_DATE, 1, 10) as REVIEW_DATE from member_profile as mp join rest_review as rr on mp.member_id = rr.member_id join (
SELECT mp.member_id, count(mp.member_id) as qq from member_profile as mp join rest_review as rr on mp.member_id = rr.member_id
group by mp.member_id having qq = (select max(qq) as qwe from 
(SELECT mp.member_name, rr.review_text, rr.review_date, count(mp.member_id) as qq from member_profile as mp join rest_review as rr on mp.member_id = rr.member_id
group by mp.member_id) as t)) as qweqwe on mp.member_id = qweqwe.member_id
order by REVIEW_DATE asc, REVIEW_TEXT asc


