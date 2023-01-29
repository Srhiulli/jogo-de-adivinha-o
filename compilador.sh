#!/bin/bash

INPUT_FILE=./src/main.c
OUTPUT_FILE=./src/main.executavel

echo '[INFO] Compilando'
cc $INPUT_FILE -o $OUTPUT_FILE

echo '[INFO] Executando'
 $OUTPUT_FILE

sleep 90
