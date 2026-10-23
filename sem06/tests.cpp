#include <gtest/gtest.h>
#include <string>
#include "TextDocument.h"

TEST(Constructor, Default) {
    TextDocument d;
    EXPECT_FALSE(d.getId().empty());
    EXPECT_EQ(d.getSize(), 0);
    EXPECT_EQ(d.getContent(), "");
    EXPECT_EQ(d.getHistoryCount(), 0);
}

TEST(Constructor, Initialization) {
    TextDocument d("Hello");
    EXPECT_EQ(d.getContent(), "Hello");
    EXPECT_EQ(d.getSize(), 5);
    EXPECT_EQ(d.getHistoryCount(), 0);
}

TEST(Constructor, Copy) {
    TextDocument a("Hello");
    a.setContent("World!");
    TextDocument b(a);
    EXPECT_EQ(b.getContent(), a.getContent());
    EXPECT_EQ(b.getSize(), a.getSize());
    EXPECT_EQ(b.getHistoryCount(), 1);
    EXPECT_EQ(b.getHistory(0), 5);
    EXPECT_NE(b.getId(), a.getId());      // у копии свой id
}

TEST(Constructor, CopyIsIndependent) {
    TextDocument a("Hello");
    TextDocument b(a);
    b.setContent("Changed");
    EXPECT_EQ(a.getContent(), "Hello");   // оригинал не изменился
    EXPECT_EQ(a.getHistoryCount(), 0);
}

TEST(Assignment, CopiesDataKeepsId) {
    TextDocument a("Hello");
    TextDocument b;
    std::string oldId = b.getId();
    b = a;
    EXPECT_EQ(b.getContent(), "Hello");
    EXPECT_EQ(b.getSize(), 5);
    EXPECT_EQ(b.getId(), oldId);          // id не меняется
}

TEST(Assignment, Self) {
    TextDocument a("Hello");
    a = a;
    EXPECT_EQ(a.getContent(), "Hello");
    EXPECT_EQ(a.getSize(), 5);
}

TEST(Id, Unique) {
    TextDocument a, b, c;
    EXPECT_NE(a.getId(), b.getId());
    EXPECT_NE(b.getId(), c.getId());
}

TEST(Normalize, ExtraSpaces) {
    TextDocument d("   Hello    world   ");
    EXPECT_EQ(d.getContent(), "Hello world");
    EXPECT_EQ(d.getSize(), 11);
}

TEST(Normalize, TooLong) {
    TextDocument d(std::string(80, 'a'));
    EXPECT_EQ(d.getSize(), TextDocument::MAX_SIZE);
}

TEST(Normalize, SizeNotNegative) {
    TextDocument d("      ");
    EXPECT_EQ(d.getSize(), 0);
}

TEST(Setter, SetContentSavesHistory) {
    TextDocument d("abc");
    d.setContent("abcdef");
    EXPECT_EQ(d.getContent(), "abcdef");
    EXPECT_EQ(d.getSize(), 6);
    EXPECT_EQ(d.getHistoryCount(), 1);
    EXPECT_EQ(d.getHistory(0), 3);
}

TEST(Setter, HistoryKeepsLast10) {
    TextDocument d("a");
    for (int i = 2; i <= 12; ++i) d.setContent(std::string(i, 'a'));   // 11 изменений
    EXPECT_EQ(d.getHistoryCount(), TextDocument::HISTORY_SIZE);
    EXPECT_EQ(d.getHistory(0), 2);        // размер 1 вытеснен
    EXPECT_EQ(d.getHistory(9), 11);
}

TEST(Getter, HistoryOutOfRange) {
    TextDocument d("abc");
    EXPECT_EQ(d.getHistory(0), -1);
    EXPECT_EQ(d.getHistory(-1), -1);
}
