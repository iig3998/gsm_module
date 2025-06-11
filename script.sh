#!/bin/bash

export FILTER_BRANCH_SQUELCH_WARNING=1 # This will suppress the warning shown by git

git filter-branch -f --env-filter '
    if test "$GIT_AUTHOR_EMAIL" = "fabio.molon@athonet.com"
    then
        GIT_AUTHOR_NAME="Fabio Molon"
        GIT_AUTHOR_EMAIL=fabiomolon85@gmail.com
    fi
    if test "$GIT_COMMITTER_EMAIL" = "fabio.molon@athonet.com"
    then
        GIT_COMMITTER_NAME="Fabio Molon"
        GIT_COMMITTER_EMAIL=fabiomolon85@gmail.com
    fi
' HEAD
