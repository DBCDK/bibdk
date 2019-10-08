#!/usr/bin/env bash

# check if given string containts the substring feature
is_feature(){
if [[ "$1" =~ "feature" ]]; then
return 0
fi
return 1
}

# get an array of feature names
get_revlist(){
features=[]
revlist=$(git ls-remote --heads)
for word in $revlist
do
if is_feature $word
then
featurename=$(echo $word | cut -d/ -f4)
echo ${featurename//_/-}
features=("${features[@]}" ${featurename//_/-})
fi
done
}

get_revlist

