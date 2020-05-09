package com.itheima.domain;

import java.util.List;

/**
 * @Author LC
 * @Date 2020/5/7 22:10
 * @Version 1.0
 */
public class QueryVo {
    private User user;
    private List<Integer> ids;

    public User getUser() {
        return user;
    }

    public void setUser(User user) {
        this.user = user;
    }

    public List<Integer> getIds() {
        return ids;
    }

    public void setIds(List<Integer> ids) {
        this.ids = ids;
    }
}
