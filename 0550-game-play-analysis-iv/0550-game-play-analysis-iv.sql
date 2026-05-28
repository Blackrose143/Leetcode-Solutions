Select 
    Round( count(distinct player_id)/
    (select count(distinct player_id) From Activity),2) As fraction
From 
    Activity
Where
    (player_id,date_sub(event_date,Interval 1 day)) In
    (Select player_id , min(event_date) As last_date 
    From Activity Group by player_id);