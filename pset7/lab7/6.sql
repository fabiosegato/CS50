select
a.name
from songs a
inner join artists b on b.id = a.artist_id
where b.name = 'Post Malone';