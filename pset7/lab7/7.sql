select
avg(a.energy) as avg_energy
from songs a
inner join artists b on b.id = a.artist_id
where b.name = 'Drake';