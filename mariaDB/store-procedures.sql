USE metro_cdmx;

DELIMITER //
CREATE PROCEDURE calculate_distance_between_stations(
    IN station_1 POINT,
    IN station_2 POINT,
    IN meters BOOLEAN
)
BEGIN
    /*
    
    SELECT ST_Distance_Sphere(station_1,
    station_2) / IF(meters, 1, 1000) AS distance;
    
    */
    IF meters THEN
        SELECT ST_Distance_Sphere(station_1,
        station_2) AS distance;
    ELSE
        SELECT ST_Distance_Sphere(station_1,
        station_2) / 1000 AS distance;
    END IF;
END //
DELIMITER ;

/*

## LLAMADA A PROCEDIMIENTO
CALL calculate_distence_between_stations(POINT(X, Y), POINT(X, Y));

*/