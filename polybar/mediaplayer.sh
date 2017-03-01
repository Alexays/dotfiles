title=$(playerctl metadata xesam:title 2>&1 >/dev/null)
artist=$(playerctl metadata xesam:artist 2>&1 >/dev/null)
if [ "$title" != "Connection to player failed: No players found" ];then
    title=$(playerctl metadata xesam:title)
    artist=$(playerctl metadata xesam:artist)
    if [ "$title" != "" ];then
	echo -e "$artist - $title"
    else
	exit 1
    fi
else
    exit 1
fi
