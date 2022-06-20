CREATE FOREIGN TABLE ##TAB## (
    trip_id                 INTEGER,
    vendor_id               TEXT ENCODING DICT,
    pickup_datetime         TIMESTAMP,
    dropoff_datetime        TIMESTAMP,
    store_and_fwd_flag      TEXT ENCODING DICT,
    rate_code_id            SMALLINT,
    pickup_longitude        DECIMAL(14,2),
    pickup_latitude         DECIMAL(14,2),
    dropoff_longitude       DECIMAL(14,2),
    dropoff_latitude        DECIMAL(14,2),
    passenger_count         SMALLINT,
    trip_distance           DECIMAL(14,2),
    fare_amount             DECIMAL(14,2),
    extra                   DECIMAL(14,2),
    mta_tax                 DECIMAL(14,2),
    tip_amount              DECIMAL(14,2),
    tolls_amount            DECIMAL(14,2),
    ehail_fee               DECIMAL(14,2),
    improvement_surcharge   DECIMAL(14,2),
    total_amount            DECIMAL(14,2),
    payment_type            TEXT ENCODING DICT,
    trip_type               SMALLINT,
    pickup                  TEXT ENCODING DICT,
    dropoff                 TEXT ENCODING DICT,
    dummy       text ,
    dummy1      text ,
    cab_type                TEXT ENCODING DICT,
    precipitation           SMALLINT,
    snow_depth              SMALLINT,
    snowfall                SMALLINT,
    max_temperature         SMALLINT,
    min_temperature         SMALLINT,
    average_wind_speed      SMALLINT,
    pickup_nyct2010_gid     SMALLINT,
    pickup_ctlabel          TEXT ENCODING DICT,
    pickup_borocode         SMALLINT,
    pickup_boroname         TEXT ENCODING DICT,
    pickup_ct2010           TEXT ENCODING DICT,
    pickup_boroct2010       TEXT ENCODING DICT,
    pickup_cdeligibil       TEXT ENCODING DICT,
    pickup_ntacode          TEXT ENCODING DICT,
    pickup_ntaname          TEXT ENCODING DICT,
    pickup_puma             TEXT ENCODING DICT,
    dropoff_nyct2010_gid    SMALLINT,
    dropoff_ctlabel         TEXT ENCODING DICT,
    dropoff_borocode        SMALLINT,
    dropoff_boroname        TEXT ENCODING DICT,
    dropoff_ct2010          TEXT  ENCODING DICT,
    dropoff_boroct2010      TEXT  ENCODING DICT,
    dropoff_cdeligibil      TEXT  ENCODING DICT,
    dropoff_ntacode         TEXT  ENCODING DICT,
    dropoff_ntaname         TEXT ENCODING DICT,
    dropoff_puma            TEXT  ENCODING DICT
) SERVER default_local_parquet WITH ( file_path = '##FILE##', refresh_update_type = 'append')
