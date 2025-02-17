/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Kick.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 04:43:37 by minhulee          #+#    #+#             */
/*   Updated: 2025/02/17 04:54:19 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

// Command: KICK
// Parameters: <channel> <user> *( "," <user> ) [<comment>]

// user를 channel에서 추방한다. - 복수 가능
// comment가 주어지지 않은 경우, 일련의 메세지를 추가한다

// 여러 사용자가 추방 될 때, 여러 번의 KICK이 보내져야 한다.
// -> comments가 있는 경우, 추방된 사용자 수만큼 있어야 한다. (irc 권고)
// -> 부족한 경우, 에러는 아니나 기본 메세지를 사용한다.

// TARGMAXRPL_ISUPPORT 매개 변수를 통해 최대 추방자 수를 정의한다.
// 서버 운영자가 없으므로, 값의 변경은 불가

// ERR_NEEDMOREPARAMS (461) - 파람부족
// 461 "<client> <command> :Not enough parameters"

// ERR_NOSUCHCHANNEL (403) - 채널 없음
// 403 "<client> <channel> :No such channel"

// ERR_CHANOPRIVSNEEDED (482) - 권한 없음
// 482 "<client> <channel> :You're not channel operator"

// ERR_USERNOTINCHANNEL (441) - 대상이 채널에 속하지 않음
// 441 "<client> <nick> <channel> :They aren't on that channel"

// ERR_NOTONCHANNEL (442) - 채널에 속하지 않음
// 442 "<client> <channel> :You're not on that channel"

// ERR_BADCHANMASK (476) - 올바르지 않은 채널명
// 476 "<channel> :Bad Channel Mask"
// -> 존재하지 않는 채널 명이 아닌 채널명의 유효성에 대한 에러