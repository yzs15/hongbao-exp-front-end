while : ;
do
    CURTIME_NS=`date +%s%N`
    
    CURTIME=`date --rfc-3339=ns`
    MS=`echo $CURTIME | cut -d '.'  -f 2 | cut -c-3`
    NEW_MS=$(($MS + 20))
    if [ $NEW_MS -gt 999 ]; then
        continue
    fi
    NEWTIME=`echo $CURTIME | sed -r "s/(.{20})(.{3})(.*)/\1$NEW_MS\3/"`
    # echo ${CURTIME}
    # echo ${NEWTIME}
    
    date --set="${NEWTIME}"    
    
    NOWTIME_NS=`date +%s%N`
    echo $(($NOWTIME_NS - $CURTIME_NS))
    
    break
done