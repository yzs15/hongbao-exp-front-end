#!/bin/bash
cd $(dirname "$0")
cd ..

rsync -aP ub20:hongbao/qt/src ./