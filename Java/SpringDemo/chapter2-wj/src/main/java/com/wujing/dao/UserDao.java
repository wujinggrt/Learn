package com.wujing.dao;

import com.wujing.domain.User;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.jdbc.core.RowCallbackHandler;
import org.springframework.stereotype.Repository;

import java.sql.ResultSet;
import java.sql.SQLException;

// define a DAO
@Repository
public class UserDao {
    private JdbcTemplate jdbcTemplate;

    private final static String MATCH_COUNT_SQL = " SELECT COUNT(*) FROM t_user " +
            " WHERE user_name=? and password=? ";
    private final static String UPDATE_LOGIN_INFO_SQL = " UPDATE t_user SET " +
            " last_visit=?, last_ip=?, credits=? WHERE user_id=? ";

    /**
     * get match count by username and password.
     *
     * @param userName
     * @param password
     * @return 1 means correct, 0 false.
     */
    public int getMatchCount(String userName, String password) {

        return jdbcTemplate.queryForObject(MATCH_COUNT_SQL, new Object[]{userName, password}, Integer.class);
    }
    public User findUserByUserName(final String userName) {
        String sqlStr = " SELECT user_id, user_name, credits, " +
                " FROM t_user WHERE user_name=? ";
        final User user = new User();
        jdbcTemplate.query(sqlStr, new Object[]{userName},
                new RowCallbackHandler() {
                    public void processRow(ResultSet resultSet) throws SQLException {
                        user.setUserId(resultSet.getInt("user_id"));
                        user.setUserName(userName);
                        user.setCredits(resultSet.getInt("credits"));
                    }
                });
        return user;
    }

    /**
     * public void updateLoginInfo(User user) {
     *      jdbcTemplate.update(UPDATE_LOGIN_INFO_SQL, new Object[] { user.getLastVisit(),
     *      user.getLastIp(),user.getCredits(),user.getUserId()});
     *      }
     * the old code(which is out-of-date) with book, api not fits.
     *
     */
    public void updateLoginInfo(User user) {
        jdbcTemplate.update(
                    UPDATE_LOGIN_INFO_SQL,
                    user.getLastVisit(),
                    user.getLastIp(),
                    user.getCredits(),
                    user.getUserId()
        );
    }

    /**
     * automatically inject Bean.
     * @param jdbcTemplate
     */
    @Autowired
    public void setJdbcTemplate(JdbcTemplate jdbcTemplate) {
        this.jdbcTemplate = jdbcTemplate;
    }
}
