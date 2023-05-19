select
c.name
from
stars b
inner join people c on c.id = b.person_id
where
c.name != 'Kevin Bacon' and c.birth != 1958
and
b.movie_id in (
select
movie_id
from
movies a
inner join stars b on b.movie_id = a.id
inner join people c on c.id = b.person_id
where c.name = 'Kevin Bacon' and c.birth = 1958
)
order by c.name;