USE metro_cdmx;

-- USANDO TRIGGERS PARA LA ACTUALIZACION DE COLUMNAS
CREATE TRIGGER update_updated_at_field
BEFORE UPDATE
ON `lines`
FOR EACH ROW
SET NEW.updated_at = NOW();

CREATE TRIGGER update_updated_at_field_stations
BEFORE UPDATE
ON `stations`
FOR EACH ROW
SET NEW.updated_at = NOW();