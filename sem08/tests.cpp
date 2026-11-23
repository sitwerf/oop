#include "TextDocument.h"

#include <gtest/gtest.h>
#include <utility>

class TextDocumentFixture : public testing::Test {
protected:
    TextDocument document{"first"};

    void SetUp() override {
        document.setContent("second");
    }
};

TEST_F(TextDocumentFixture, CopyConstructorKeepsSource) {
    TextDocument copy(document);

    EXPECT_EQ(copy.getContent(), "second");
    EXPECT_EQ(document.getContent(), "second");
    EXPECT_NE(copy.getId(), document.getId());
    EXPECT_EQ(copy.getHistory(0), 5);
}

TEST_F(TextDocumentFixture, MoveConstructorEmptiesSource) {
    TextDocument moved(std::move(document));

    EXPECT_EQ(moved.getContent(), "second");
    EXPECT_EQ(moved.getHistory(0), 5);
    EXPECT_TRUE(document.getContent().empty());
    EXPECT_EQ(document.getSize(), 0);
}

TEST_F(TextDocumentFixture, CopyAssignmentKeepsBothObjects) {
    TextDocument target;
    const std::string targetId = target.getId();

    target = document;

    EXPECT_EQ(target.getContent(), "second");
    EXPECT_EQ(document.getContent(), "second");
    EXPECT_EQ(target.getId(), targetId);
}

TEST_F(TextDocumentFixture, MoveAssignmentEmptiesSource) {
    TextDocument target;
    const std::string targetId = target.getId();

    target = std::move(document);

    EXPECT_EQ(target.getContent(), "second");
    EXPECT_EQ(target.getId(), targetId);
    EXPECT_TRUE(document.getContent().empty());
    EXPECT_EQ(document.getSize(), 0);
}

TEST_F(TextDocumentFixture, MovedObjectCanBeUsedAgain) {
    TextDocument target(std::move(document));
    document.setContent("new text");

    EXPECT_EQ(document.getContent(), "new text");
    EXPECT_EQ(document.getSize(), 8);
}
