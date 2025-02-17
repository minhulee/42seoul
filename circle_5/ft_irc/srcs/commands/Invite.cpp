/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Invite.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 04:54:41 by minhulee          #+#    #+#             */
/*   Updated: 2025/02/17 04:59:55 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

// Command: INVITE
// Parameters: <nickname> <channel>

// nickname을 channel에 초대한다.
// INVITE Wiz #foo_bar

// RPL_INVITING (341) - 정상 동작
// 341 "<client> <nick> <channel>"

// ERR_NEEDMOREPARAMS (461) - 파람 부족
// 461 "<client> <command> :Not enough parameters"

// ERR_NOSUCHCHANNEL (403) - 채널 없음
// 403 "<client> <channel> :No such channel"

// ERR_NOTONCHANNEL (442) - 채널에 속하지 않음
// 442 ERR_NOTONCHANNEL (442) 

// ERR_CHANOPRIVSNEEDED (482) - 권한 없음
// 482 ERR_CHANOPRIVSNEEDED (482) 

// ERR_USERONCHANNEL (443) - 채널에 이미 존재함
// 443 "<client> <nick> <channel> :is already on channel"