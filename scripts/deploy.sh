#!/bin/bash
cd $(dirname "$0")
cd ..

if [ $# -lt 1 ]; then
  echo "usage: deploy.sh SERVER"
  exit 1
fi


SERVER=$1

PRO_DIR='~/projects/hongbao-fe'

rsync -aP ./* $SERVER:$PRO_DIR/