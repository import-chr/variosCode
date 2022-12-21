USE metro_cdmx;

DELETE FROM `stations`
WHERE id = 164;

DELETE FROM `stations`
WHERE id = 165;

DELETE FROM `stations`
WHERE id = 166;

-- ELIMINACION TABLA
DROP TABLE `stations_delete`;

/*

## VACIADO DE TABLA
DELETE FROM `stations_delete`

## REINICIO DE ID's
TRUNCATE TABLE `stations_delete`

*/