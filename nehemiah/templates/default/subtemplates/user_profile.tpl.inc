{config_load file=$settings.language_file section="user_show"}
{include file="$template/subtemplates/ajax_preview.tpl.inc"}
{if $user_name}
<table class="normaltab wide" border="0" cellpadding="5" cellspacing="1">
<tr>
<td class="c"><p class="userdata"><strong>{#user_name#}</strong></p></td>
<td class="d"><p class="userdata"><strong>{$user_name}</strong>{if $gender==1} <img src="templates/{$settings.template}/images/male.png" alt="{#male#}" width="16" height="16" />{elseif $gender==2} <img src="templates/{$settings.template}/images/female.png" alt="{#female#}" width="16" height="16" />{/if} <span class="xsmall">{if $user_type==2}({#admin#}){elseif $user_type==1}({#mod#}){else}<!--({#user#})-->{/if}</span></p></td>
</tr>
{if $avatar}
<tr>
<td class="c"><p class="userdata"><strong>{#user_avatar#}</strong></p></td>
<td class="d"><p class="userdata"><img src="{$avatar.image}" alt="{#avatar_img_alt#}" width="{$avatar.width}" height="{$avatar.height}" /></p></td>
</tr>
{/if}
{if $user_hp || $user_email}
<tr>
<td class="c"><p class="userdata"><strong>{#user_hp_email#}</strong></p></td>
<td class="d"><p class="userdata">{if $user_hp=='' && $user_email==''}-{/if}{if $user_hp!=''}<a href="{$user_hp}" title="{$user_hp}"><img src="templates/{$settings.template}/images/homepage.png" alt="{#homepage#}" width="13" height="13" /></a> &nbsp;{/if}{if $user_email}<a href="index.php?mode=contact&amp;user_id={$p_user_id}" title="{#mailto_user#|replace:"[user]":$user_name}"><img src="templates/{$settings.template}/images/email.png" alt="{#email#}" width="13" height="10" /></a>{/if}</p></td>
</tr>
{/if}
{if $user_real_name}
<tr>
<td class="c"><p class="userdata"><strong>{#user_real_name#}</strong></p></td>
<td class="d"><p class="userdata">{$user_real_name|default:'-'}</p></td>
</tr>
{/if}
{if $birthdate}
<tr>
<td class="c"><p class="userdata"><strong>{#age_birthday#}</strong></p></td>
<td class="d"><p class="userdata">{$years} / {$birthdate.day}.{$birthdate.month}.{$birthdate.year}</p></td>
</tr>
{/if}
{if $user_location}
<tr>
<td class="c"><p class="userdata"><strong>{#user_location#}</strong></p></td>
<td class="d"><p class="userdata">{$user_location|default:'-'}</p></td>
</tr>
{/if}
<tr>
<td class="c"><p class="userdata"><strong>{#user_registered#}</strong></p></td>
<td class="d"><p class="userdata">{$user_registered}</p></td>
</tr>
{if $user_last_login}
<tr>
<td class="c"><p class="userdata"><strong>{#user_last_login#}</strong></p></td>
<td class="d"><p class="userdata">{$user_last_login|default:'-'}</p></td>
</tr>
{/if}
<tr>
<td class="c"><p class="userdata"><strong>{#user_logins#}</strong></p></td>
<td class="d"><p class="userdata">{$logins}</p></td>
</tr>
<tr>
<td class="c"><p class="userdata"><strong>{#logins_per_day#}</strong></p></td>
<td class="d"><p class="userdata">{$logins_per_day}</p></td>
</tr>
<tr>
<td class="c"><p class="userdata"><strong>{#user_postings#}</strong></p></td>
<td class="d"><p class="userdata">{$postings} ({$postings_percent}%){if $postings>0} &nbsp;<span class="small">[ <a href="index.php?mode=user&amp;action=show_posts&amp;id={$p_user_id}">{#show_postings_link#}</a> ]</span>{/if}</p></td>
</tr>
<tr>
<td class="c"><p class="userdata"><strong>{#postings_per_day#}</strong></p></td>
<td class="d"><p class="userdata">{$postings_per_day}</p></td>
</tr>
{if $last_posting_subject}
<tr>
<td class="c"><p class="userdata"><strong>{#last_posting#}</strong></p></td>
<td class="d"><p class="userdata">{if $last_posting_subject}{$last_posting_time|date_format:#time_format#}: <a href="index.php?mode=entry&amp;id={$last_posting_id}">{$last_posting_subject}</a><script type="text/javascript">/* <![CDATA[ */document.write(' <a href="#" onclick="ajax_preview({$last_posting_id}); return false" title="{#ajax_preview_title#|escape:"quotes"}"><img src="templates/{$settings.template}/images/ajax_preview.png" alt="{#ajax_preview_title#|escape:"quotes"}" width="11" height="11" /><\/a>')/* ]]> */</script>{else}-{/if}</p></td>
</tr>
{/if}
{if $profile}
<tr>
<td class="c"><p class="userdata"><strong>{#user_profile#}</strong></p></td>
<td class="d">{$profile|default:'<p>-</p>'}</td>
</tr>
{/if}
</table>
{else}
<p class="caution">{#user_account_doesnt_exist#}</p>
{/if}