#!/bin/bash
cd $(dirname "$0")
cd ..

SERVER=kbnj1
PRO_DIR='~/projects/hongbao-fe'

SERVER=lab3n
PRO_DIR='~/projects/hongbao-fe'
PRO_DIR='~/projects/cs101/hongbao/qt'

rsync -aP ./* $SERVER:$PRO_DIR/